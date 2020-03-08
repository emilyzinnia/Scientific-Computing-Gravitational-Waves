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
  n = F.extent(0);
  incF = 1;
  incG = 1;
 
  // make double rarrays needed for /ddot
  double FdotF, FdotG, GdotG, corr;
  
  FdotF = cblas_ddot(n, F, incF, F, incF);
  FdotG = cblas_ddot(n, F, incF, G, incG);
  GdotG = cblas_ddot(n, G, incG, G, incG);
  
  
  corr = FdotG / sqrt( FdotF * GdotG );
  
  return corr;
  
}

void get_top_five(rvector<double> corr){
  
  rvector<int> data_index(5);   // array to store data indices
  rvector<double> top_corr(5);  // array to store top correlations

  // sort rarray 
  std::sort(corr[0], corr[ corr.extent(0) ] ); 
  
  std::cout << 
}
