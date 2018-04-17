# Install script for directory: /home/origamidance/Playground/Cinder-NumOpt/lib/nlopt

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/pkgconfig" TYPE FILE FILES "/home/origamidance/Playground/Cinder-NumOpt/build/nlopt/nlopt.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES
    "/home/origamidance/Playground/Cinder-NumOpt/build/nlopt/src/api/nlopt.h"
    "/home/origamidance/Playground/Cinder-NumOpt/build/nlopt/src/api/nlopt.hpp"
    "/home/origamidance/Playground/Cinder-NumOpt/build/nlopt/src/api/nlopt.f"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/libnlopt_cxx.so.0.9.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/libnlopt_cxx.so.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/libnlopt_cxx.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "/usr/local/lib64")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64" TYPE SHARED_LIBRARY FILES
    "/home/origamidance/Playground/Cinder-NumOpt/build/nlopt/libnlopt_cxx.so.0.9.0"
    "/home/origamidance/Playground/Cinder-NumOpt/build/nlopt/libnlopt_cxx.so.0"
    "/home/origamidance/Playground/Cinder-NumOpt/build/nlopt/libnlopt_cxx.so"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/libnlopt_cxx.so.0.9.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/libnlopt_cxx.so.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/libnlopt_cxx.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHANGE
           FILE "${file}"
           OLD_RPATH "::::::::::::::::"
           NEW_RPATH "/usr/local/lib64")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/cmake/nlopt/NLoptLibraryDepends.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/cmake/nlopt/NLoptLibraryDepends.cmake"
         "/home/origamidance/Playground/Cinder-NumOpt/build/nlopt/CMakeFiles/Export/lib64/cmake/nlopt/NLoptLibraryDepends.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/cmake/nlopt/NLoptLibraryDepends-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/cmake/nlopt/NLoptLibraryDepends.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/cmake/nlopt" TYPE FILE FILES "/home/origamidance/Playground/Cinder-NumOpt/build/nlopt/CMakeFiles/Export/lib64/cmake/nlopt/NLoptLibraryDepends.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/cmake/nlopt" TYPE FILE FILES "/home/origamidance/Playground/Cinder-NumOpt/build/nlopt/CMakeFiles/Export/lib64/cmake/nlopt/NLoptLibraryDepends-release.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/cmake/nlopt" TYPE FILE FILES
    "/home/origamidance/Playground/Cinder-NumOpt/build/nlopt/NLoptConfig.cmake"
    "/home/origamidance/Playground/Cinder-NumOpt/build/nlopt/NLoptConfigVersion.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/origamidance/Playground/Cinder-NumOpt/build/nlopt/src/api/cmake_install.cmake")
  include("/home/origamidance/Playground/Cinder-NumOpt/build/nlopt/test/cmake_install.cmake")

endif()

