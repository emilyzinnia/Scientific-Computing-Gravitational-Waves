// correlation.cc 

#include <rarray>
#include <cmath>
#include <cblas.h>
#include "correlation.h"


float correlation( rvector<float> F, rvector<float> G ){
  int n, incF, incG;
  n = F.extent(0);
  incF = 1;
  incG = 1;
 
  // make const float rarrays needed for sdot

  rvector<const float> F_const = F; 
  rvector<const float> G_const = G;

  float FdotF, FdotG, GdotG, corr;
  FdotF = cblas_sdot(n, F_const.data(), incF, F_const.data(), incF);
  FdotG = cblas_sdot(n, F_const.data(), incF, G_const.data(), incG);
  GdotG = cblas_sdot(n, G_const.data(), incG, G_const.data(), incG);

  corr = FdotG / sqrt( FdotF * GdotG );

  return corr;
  
}
