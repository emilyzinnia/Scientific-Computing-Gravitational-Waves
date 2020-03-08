// util.cc

#include <rarray>
#include <rarrayio>
#include <iostream>
#include <algorithm>
#include "util.h"

int compare(const void *arg1, const void *arg2){

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
  
  int n = arr.extent(0); 

  // sort correlations from lowest to highest
  std::qsort( arr.data(), n, sizeof(*arr.data())*2,
	      compare );

    // print last five elements 
  std::cout << "The datasets with the largest correlations are:" << std::endl;
  
  for (int i = n-1; i > n-6; i--){
       std::cout << "Dataset: " << arr[i][0] 
    	      << "\t Correlation: " << arr[i][1] << std::endl;
  } 
  
}

rarray<double,2> zeros( int n, int m ){
  rarray<double,2> r(n,m);
  r.fill(0.0);
  return r;
}
