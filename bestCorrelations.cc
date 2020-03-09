// bestCorrelations.cc
// Emily Zhang
// March 2020
//
// Main module. The program reads the data files from a defined path. The power is then 
// computed using the Fourier components of the data, and the correlations between the 
// detection data and GW predictions are computed. The program then prints out the 
// top five data sets with the highest correlations.
//
//
// Compile with:
//     make gw 
//
// On the clusters, it will be necessary to load 
//     module load gcc rarray hdf5 netcdf fftw
//
// Additionally, openblas is not listed on module spider, so it needs to be installed 
// to the home folder. The library and inc paths must also be exported to 
// SCINET_OPENBLAS_LIB and SCINET_OPENBLAS_INC respectively.
//
// Run with 
//     ./gw {NUM OF DATA FILES} {PATH TO DATA FILES}
// 
// E.g. ./gw 32 /scinet/course/phy1610/gwdata/
//
// **********************************************************************


#include <rarray>
#include <iostream>
#include <rarrayio>
#include <complex>
#include "read_nc.h"
#include "signal_processing.h"
#include "correlation.h"
#include "util.h"

using namespace std; 

int main(int argc, char** argv){

  // number of detection files
  int n = atoi(argv[1]);

  // create array to store correlations and data index
  rarray<double,2> correlations(n,2); 

  // define path to data files
  string path = argv[2];
  string file_prefix = "detection";
  
  // Read GW prediction
  rvector<std::complex<double>> GW_pred = read_GW_data( path+"GWprediction.nc");

  // Fourier transform GW prediction
  rvector<std::complex<double>> GW_FFT( GW_pred.extent(0) );
  fft_signal( GW_pred, GW_FFT );
  
  // Compute power spectrum of GW prediction
  rvector<double> power_GW = compute_power( GW_FFT ); 

  // loop over detection files and compute correlations
  for (int i=0; i<n; i++){

    // construct filename
    string num_prefix = i+1<10? "0": "";       // if i<10 then append "0" to beginning
    string detection_num = num_prefix  + to_string(i+1); 
    string filename = path + file_prefix + detection_num + ".nc";
    
    // Read detection data
    rvector<std::complex<double>> detection_data = read_GW_data( filename ); 

    // Fourier transform detection data
    rvector<std::complex<double>> data_FFT(detection_data.extent(0));
    fft_signal( detection_data, data_FFT );

    // Compute power spectrum of data
    rvector<double> power_data = compute_power( data_FFT ); 
    
    // Compute correlation functions and store them in array 
    correlations[i][0] = (double) i+1; // data index
    correlations[i][1] = correlation( power_GW, power_data ); // correlation 
   
  }
  
  print_top_five(correlations);

}
