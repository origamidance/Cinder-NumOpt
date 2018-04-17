#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "NLopt::nlopt_cxx" for configuration "Release"
set_property(TARGET NLopt::nlopt_cxx APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(NLopt::nlopt_cxx PROPERTIES
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE "m"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib64/libnlopt_cxx.so.0.9.0"
  IMPORTED_SONAME_RELEASE "libnlopt_cxx.so.0"
  )

list(APPEND _IMPORT_CHECK_TARGETS NLopt::nlopt_cxx )
list(APPEND _IMPORT_CHECK_FILES_FOR_NLopt::nlopt_cxx "${_IMPORT_PREFIX}/lib64/libnlopt_cxx.so.0.9.0" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
