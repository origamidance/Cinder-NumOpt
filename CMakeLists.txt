cmake_minimum_required (VERSION 2.8.11)
set(CMAKE_CXX_STANDARD 14)
macro(SET_OPTION option value)
  set(${option} ${value} CACHE "" INTERNAL FORCE)
endmacro()
project(cinder-numopt)
# SET_OPTION(NLOPT_CXX ON)
# SET_OPTION(NLOPT_PYTHON OFF)
# SET_OPTION(NLOPT_OCTAVE OFF)
# SET_OPTION(NLOPT_MATLAB OFF)
# SET_OPTION(NLOPT_GUILE OFF)
# SET_OPTION(NLOPT_SWIG OFF)
# add_subdirectory(lib/nlopt nlopt)
add_executable(testnlopt src/test.cpp)

find_package(Eigen3 REQUIRED)
find_package(Boost COMPONENTS REQUIRED)
get_filename_component( LIB_DIR "${CMAKE_CURRENT_LIST_DIR}/lib" ABSOLUTE )
list(APPEND INCLUDE_DIRS
  ${LIB_DIR}/stan/math
  # ${LIB_DIR}/stan/math/lib/boost_1.66.0
  # ${LIB_DIR}/stan/math/lib/eigen_3.3.3
  ${LIB_DIR}/stan/math/lib/cvodes-3.1.0/include
  ${EIGEN3_INCLUDE_DIR}
  ${BOOST_INCLUDE_DIRS}
  )
include_directories(testnlopt ${INCLUDE_DIRS})
# link_directories(nlopt)
target_link_libraries(testnlopt nlopt)
