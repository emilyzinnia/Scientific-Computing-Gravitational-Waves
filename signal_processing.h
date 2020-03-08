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
void fft_signal(rvector<complex>& f, rvector<complex>& fhat);

// Function that computes the power given the Fourier components of the signal 
rvector<double> compute_power(rvector<complex> fhat);

#endif
