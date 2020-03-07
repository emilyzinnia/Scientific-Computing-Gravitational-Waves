// signal_processing.cc

#include <rarray>
#include <complex>
#include <fftw3.h>
#include "signal_processing.h"

typedef std::complex<double> complex;

// Function that computes the fast Fourier Transform of a given signal                          
void fft_signal(rvector<complex>& f, rvector<complex>& fhat){
  int n = f.size();
  fftw_plan p = fftw_plan_dft_1d(n,
				 (fftw_complex*)f.data(), (fftw_complex*)fhat.data(),
				 FFTW_FORWARD,
				 FFTW_ESTIMATE);
  fftw_execute(p);
  fftw_destroy_plan(p);
}
// Function that computes the power given the Fourier components of the signal                  
rvector<float> compute_power(rvector<complex> fhat){

  int length = fhat.extent(0);
  rvector<float> pow( length );
  
  for (int i = 0; i<length; i++){
    float norm = std::norm( fhat[i] );
    pow[i] = norm * norm;
  }

  return pow;
}
