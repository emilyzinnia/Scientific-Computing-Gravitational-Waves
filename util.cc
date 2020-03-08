// util.cc

#include <rarray>
#include <rarrayio>
#include <iostream>
#include <algorithm>
#include "util.h"

int compare(const void *, const void *arg2){

  // casting pointers to local variables lhs and rhs 
  double const *lhs = static_cast<double const*>(arg1);
  double const *rhs = static_cast<double const*>(arg2);

  // comparing the second elements in the array 
  if (lhs[1] < rhs[1]){
    return -1;
  } else if (rhs[1] < lhs[1]) {
    return 1;
  } else {
    return 0;
  }
  
}

void print_top_five(rarray<double,2> arr){
  rarray<double,2> top_five= zeros(5, 2);  // array to store top correlations and indices

  std::qsort( arr.data(), arr.extent(0), sizeof(*arr.data()),
	      compare );

  std::cout << arr << std::endl; 
  
}

rarray<double,2> zeros( int n, int m ){
  rarray<double,2> r(n,m);
  r.fill(0.0);
  return r;
}
