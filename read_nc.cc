// read_nc.cc 

#include <netcdf>
#include <rarray>
#include <complex>
#include "read_nc.h"

using namespace netCDF; 

typedef std::complex<double> complex;

rvector<std::complex<double>> read_GW_data( std::string filename){
  NcFile ncfile(filename, NcFile::read);
  rvector<complex> f(ncfile.getDim("nt").getSize());
  ncfile.getVar("f").getVar(f.data());
  
  return f;
}
