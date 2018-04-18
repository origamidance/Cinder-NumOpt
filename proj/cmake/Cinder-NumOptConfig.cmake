if( NOT TARGET Cinder-NumOpt )
  get_filename_component( CINDER-NUMOPT_PATH "${CMAKE_CURRENT_LIST_DIR}/../.." ABSOLUTE )
	get_filename_component( CINDER_PATH "${CMAKE_CURRENT_LIST_DIR}/../../../../Cinder" ABSOLUTE )
  message("CINDER PATH= ${CINDER_PATH}")
  set(STANMATH_PATH ${CINDER-NUMOPT_PATH}/lib/stan/math)
  list(APPEND CINDER-NUMOPT_SOURCES
    ${CINDER-NUMOPT_PATH}/src/test.cpp
    ${STANMATH_PATH}/math.hpp
    nlopt.hpp
    )
  add_executable(Cinder-NumOpt ${CINDER-NUMOPT_SOURCES})
  set(CMAKE_CXX_STANDARD 14)
  find_package(Eigen3 REQUIRED)
  find_package(Boost COMPONENTS REQUIRED)
  list( APPEND STANMATH_INCLUDE_DIRS
    ${STANMATH_PATH}
    ${STANMATH_PATH}/lib/cvodes-3.1.0/include
    ${EIGEN3_INCLUDE_DIR}
    ${BOOST_INCLUDE_DIRS}
    )
  target_include_directories(Cinder-NumOpt PUBLIC ${STANMATH_INCLUDE_DIRS})
  if( NOT TARGET cinder )
	include( "${CINDER_PATH}/proj/cmake/configure.cmake" )
	find_package( cinder REQUIRED PATHS
	  "${CINDER_PATH}/${CINDER_LIB_DIRECTORY}"
	  "$ENV{CINDER_PATH}/${CINDER_LIB_DIRECTORY}" )
  endif()
  target_link_libraries( Cinder-NumOpt PRIVATE cinder )
endif()
