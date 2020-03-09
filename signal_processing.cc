// signal_processing.cc

#include <rarray>
#include <complex>
#include <fftw3.h>
#include "signal_processing.h"

typedef std::complex<double> complex;

// Function that computes the fast Fourier Transform of a given signal                    
void fft_signal(rvector<complex>& f, rvector<complex>& fhat){
  int n = f.size(); // size of f array 

  // create plan for fftw
  fftw_plan p = fftw_plan_dft_1d(n,
				 (fftw_complex*)f.data(), (fftw_complex*)fhat.data(),
				 FFTW_FORWARD,   
				 FFTW_ESTIMATE);
  fftw_execute(p);      // execute plan
  fftw_destroy_plan(p); // destroy plan
}

// Function that computes the power given the Fourier components of the signal       
rvector<double> compute_power(rvector<complex> fhat){

  int length = fhat.extent(0);      // length of fhat
  rvector<double> pow( length );    // define array of length fhat to store power 
  
  // compute the power for each element in fhat 
  for (int i = 0; i<length; i++){
    double norm = std::norm( fhat[i] );   // norm = mod( complex number )^2
    pow[i] = norm ;
  }

  return pow;
}
