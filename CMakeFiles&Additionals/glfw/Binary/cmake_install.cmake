# Install script for directory: C:/Users/freecomp1/Desktop/cmakefile ggenerate/glfw-3.1.2/glfw-3.1.2

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/GLFW")
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

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "C:/Users/freecomp1/Desktop/cmakefile ggenerate/glfw-3.1.2/glfw-3.1.2/include/GLFW" FILES_MATCHING REGEX "/glfw3\\.h$" REGEX "/glfw3native\\.h$")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/glfw" TYPE FILE FILES
    "C:/Users/freecomp1/Desktop/cmakefile ggenerate/Binary/src/glfw3Config.cmake"
    "C:/Users/freecomp1/Desktop/cmakefile ggenerate/Binary/src/glfw3ConfigVersion.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/glfw/glfwTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/glfw/glfwTargets.cmake"
         "C:/Users/freecomp1/Desktop/cmakefile ggenerate/Binary/CMakeFiles/Export/lib/cmake/glfw/glfwTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/glfw/glfwTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/glfw/glfwTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/glfw" TYPE FILE FILES "C:/Users/freecomp1/Desktop/cmakefile ggenerate/Binary/CMakeFiles/Export/lib/cmake/glfw/glfwTargets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/glfw" TYPE FILE FILES "C:/Users/freecomp1/Desktop/cmakefile ggenerate/Binary/CMakeFiles/Export/lib/cmake/glfw/glfwTargets-debug.cmake")
  endif()
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/glfw" TYPE FILE FILES "C:/Users/freecomp1/Desktop/cmakefile ggenerate/Binary/CMakeFiles/Export/lib/cmake/glfw/glfwTargets-minsizerel.cmake")
  endif()
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/glfw" TYPE FILE FILES "C:/Users/freecomp1/Desktop/cmakefile ggenerate/Binary/CMakeFiles/Export/lib/cmake/glfw/glfwTargets-relwithdebinfo.cmake")
  endif()
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/glfw" TYPE FILE FILES "C:/Users/freecomp1/Desktop/cmakefile ggenerate/Binary/CMakeFiles/Export/lib/cmake/glfw/glfwTargets-release.cmake")
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "C:/Users/freecomp1/Desktop/cmakefile ggenerate/Binary/src/glfw3.pc")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/Users/freecomp1/Desktop/cmakefile ggenerate/Binary/src/cmake_install.cmake")
  include("C:/Users/freecomp1/Desktop/cmakefile ggenerate/Binary/examples/cmake_install.cmake")
  include("C:/Users/freecomp1/Desktop/cmakefile ggenerate/Binary/tests/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "C:/Users/freecomp1/Desktop/cmakefile ggenerate/Binary/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
