// read_nc.h
// Emily Zhang
// March 2020
//
// Module to read netCDF file 

#ifndef READ_NC
#define READ_NC  

#include <rarray>
#include <complex>

// Function reads GW data from netCDF file and stores data in complex rarray
//
// Parameters:
//    filename   name of file to read 

rvector<std::complex<double>> read_GW_data( std::string filename );

#endif
