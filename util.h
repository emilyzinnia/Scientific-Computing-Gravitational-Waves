// util.h
// Emily Zhang
// March 2020
//
// Includes utility functions, such as one that counts the top five of a 2D array 

#ifndef UTIL_H
#define UTIL_H

#include <rarray>

// Helper function for qsort to compare two elements. Called repeatedly by qsort;
// returns -1 if arg1 goes before arg2; 0 if arg1 = arg2; 1 if arg1 goes after arg2
//
// Parameters:
//    arg1  pointer to element a
//    arg2  pointer to element b
int compare(const void *arg1, const void *arg2);

// Function to print top five elements and their corresponding indices in a 2D array.
// Uses qsort to sort the array by correlation in ascending order, then prints the
// last five elements. 
//
// Parameters:
//    arr  A 2D rarray containing the indices in the 1st column and values in the 2nd

void print_top_five(rarray<double,2> arr);
