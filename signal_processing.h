// signal_processing.h
// Emily Zhang
// March 2020
//
// Module containing signal processing functions (e.g. FT, compute power)

#ifndef SIG_PRO
#define SIG_PRO
#include <rarray>
#include <complex>

typedef std::complex<double> complex;

// Function that computes the fast Fourier Transform of a given signal
// 
// Parameters:
//     f     complex rarray to Fourier transform
//     fhat  complex rarray to fill with FFT(f)

void fft_signal(rvector<complex>& f, rvector<complex>& fhat);


// Function that computes the power given the Fourier components of the signal 
//
// Parameters:
//     fhat  complex rarray to compute power with 

rvector<double> compute_power(rvector<complex> fhat);

#endif
