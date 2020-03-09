// correlation.cc 

#include <rarrayio>
#include <iostream>
#include <rarray>
#include <cmath>
#include <cblas.h>
#include <algorithm>
#include "correlation.h"


double correlation( rvector<double> F, rvector<double> G ){
  int n, incF, incG;
  n = F.extent(0); // size of F, G
  incF = 1;        // increment of F 
  incG = 1;        // increment of G
 
  double FdotF, FdotG, GdotG, corr;
  
  // compute dot products
  FdotF = cblas_ddot(n, F, incF, F, incF);
  FdotG = cblas_ddot(n, F, incF, G, incG);
  GdotG = cblas_ddot(n, G, incG, G, incG);
  
  // compute correlation
  corr = FdotG / sqrt( FdotF * GdotG );
  
  return corr;
  
}

