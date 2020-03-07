// bestCorrelations.cc
// Emily Zhang
// March 2020
//
// Main module

#include <rarray>
#include <iostream>
#include <rarrayio>
#include <complex>
#include "read_nc.h"
#include "signal_processing.h"
#include "correlation.h"

using namespace std; 

typedef std::complex<double> complex;


int main(){

  // number of detection files
  int n = 32;

  // create array to store correlations
  rvector<float> correlations(n); 

  // define path
  string path = "data_files/";
  string file_prefix = "detection";
  
  // Read GW prediction
  rvector<std::complex<double>> GW_pred = read_GW_data( path+"GWprediction.nc");

  // Fourier transform GW prediction
  rvector<std::complex<double>> GW_FFT( GW_pred.extent(0) );
  fft_signal( GW_pred, GW_FFT );

  // Compute power spectrum of GW prediction
  rvector<float> power_GW = compute_power( GW_FFT ); 

  // loop over detection files and compute correlations
  for (int i=0; i<n; i++){

    // construct filename
    string num_prefix = i+1<10? "0": "";
    string detection_num = num_prefix  + to_string(i+1); 
    string filename = path + file_prefix + detection_num + ".nc";

    // Read detection data
    rvector<std::complex<double>> detection_data = read_GW_data( filename ); 

    // Fourier transform detection data
    rvector<std::complex<double>> data_FFT(detection_data.extent(0));
    fft_signal( detection_data, data_FFT );

    // Compute power spectrum of data
    rvector<float> power_data = compute_power( data_FFT ); 

    // Compute correlation functions and store them in array 
    correlations[i] = correlation( power_GW, power_data ); 

    //detection_data.clear(); // release data from memory
    //power_data.clear();
    
  }
  
  cout << correlations << endl;
  // Sort correlations
  //sort(correlations);  

}
