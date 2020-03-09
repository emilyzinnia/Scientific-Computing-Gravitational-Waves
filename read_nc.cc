// read_nc.cc 

#include <netcdf>
#include <rarray>
#include <complex>
#include "read_nc.h"

using namespace netCDF; 

typedef std::complex<double> complex;

rvector<complex> read_GW_data( std::string filename){
  NcFile ncfile(filename, NcFile::read);             // Read netCDF file
  rvector<complex> f(ncfile.getDim("nt").getSize()); // Initialize rarray for data storage 
  ncfile.getVar("f").getVar(f.data());               // Dump data into rarray 
  
  return f;
}
