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

  const float* F_const = (const float*)F.data(); 
  const float* G_const = (const float*)G.data();

  float FdotF, FdotG, GdotG, corr;
  FdotF = cblas_sdot(n, F_const, incF, F_const, incF);
  FdotG = cblas_sdot(n, F_const, incF, G_const, incG);
  GdotG = cblas_sdot(n, G_const, incG, G_const, incG);

  corr = FdotG / sqrt( FdotF * GdotG );

  return corr;
  
}
