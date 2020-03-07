# Makefile for GW correlation 
# Emily Zhang
# March 2020


# *************************************************************
# Variables to control Makefile operation

# Defining a compiler for use
CXX = g++

# NetCDF library locations
NETCDF_LIB = ${SCINET_NETCDF_ROOT}/lib
NETCDF_INC = ${SCINET_NETCDF_ROOT}/include 

# BLAS library locations
BLAS_INC = ${SCINET_OPENBLAS_INC}
BLAS_LIB = ${SCINET_OPENBLAS_LIB}


# Compiler and linker flags 
CXXFLAGS = -std=c++14 -O3 -march=native
BLASFLAGS = -lopenblas
FFTFLAGS = -lfftw3
NETCDFFLAGS = -lnetcdf_c++4 -lnetcdf
LDFLAGS = ${BLASFLAGS} ${FFTFLAGS} ${NETCDFFLAGS}
LDLIBS = -L${NETCDF_LIB} -I${BLAS_INC} -L${BLAS_LIB} 


# *************************************************************
# GW correlations

gw: correlation.o signal_processing.o read_nc.o 
	$(CXX) $(CXXFLAGS) -o gw \
	correlation.o signal_processing.o readnc.o $(LDFLAGS) $(LDLIBS)

correlation.o: 
	$(CXX) -I$(BLAS_INC) $(CXXFLAGS) -c -o correlation.o correlation.cc 

signal_processing.o: 
	$(CXX) $(CXXFLAGS) -c -o signal_processing.o signal_processing.cc 

read_nc.o: 
	$(CXX) $(NETCDF_INC) $(CXXFLAGS) -c -o read_nc.o read_nc.cc 

# *************************************************************
# Clean rules 

clean: 
	rm -f *.o gw 
