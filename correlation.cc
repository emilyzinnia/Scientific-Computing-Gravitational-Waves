// correlation.cc 

#include <rarray>
#include <cmath>
#include <cblas.h>
#include "correlation.h"


double correlation( rarray<double> F, rarray<double> G ){
  int n, incF, incG;
  n = F.extent(0);
  incF = 1;
  incG = 1;

  double FdotF, FdotG, GdotG, corr;
  FdotF = sdot(n, F, incF, F, incF);
  FdotG = sdot(n, F, incF, G, incG);
  GdotG = sdot(n, G, incG, G, incG);

  corr = FdotG / sqrt( FdotF * GdotG );

  return corr;
  
}
