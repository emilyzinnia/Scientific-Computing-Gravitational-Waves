// correlation.h
// Emily Zhang
// March 2020
//
// Module that computes the correlation between two data sets

#ifndef CORR_H
#define CORR_H

#include <rarray>

// Function that computes the correlation between two vectors 
// 
// Parameters
//   F    rarray of size n 
//   G    rarray of size n
double correlation( rvector<double> F, rvector<double> G );

#endif
