// bestCorrelations.cc
// Emily Zhang
// March 2020
//
// Main module

#include <rarray>
#include <iostream>

#include "read_nc.h"
#include "signal_processing.h"
#include "correlation.h"

using namespace std;

typedef complex<double> complex;

int main(){

  // number of detection files
  int n = 32;

  // create array to store correlations
  rvector<double> correlations(n); 

  // define path
  string path = "data_files/";
  string file_prefix = "detection";
  
  // Read GW prediction
  rvector<complex> GW_pred = read_GW_data( path+"GWprediction.nc");

  // Fourier transform GW prediction
  rvector<complex> GW_FFT( GW_pred.extent(0) );
  fft_signal( GW_pred, GW_FFT );

  // Compute power spectrum of GW prediction
  rvector<double> power_GW = compute_power( GW_FFT ); 

  // loop over detection files and compute correlations
  for (int i=0; i<n; i++){

    // construct filename
    string detection_num = to_string(i+1); 
    string filename = path + file_prefix + detection_num + ".nc";

    // Read detection data
    rvector<complex> detection_data = read_GW_data( filename ); 

    // Fourier transform detection data
    rvector<complex> data_FFT(detection_data.extent(0));
    fft_signal( detection_data, data_FFT );

    // Compute power spectrum of data
    rvector<double> pow_data = compute_power( data_FFT ); 

    // Compute correlation functions and store them in array 
    correlations[i] = correlation( power_GW, power_data ); 

    detection_data.clear(); // release data from memory
    pow_data.clear();
    
  }

  // Sort correlations
  sort(correlations);
  

}
