#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "GLEW::glew" for configuration "Debug"
set_property(TARGET GLEW::glew APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(GLEW::glew PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/glew32d.lib"
  IMPORTED_LINK_INTERFACE_LIBRARIES_DEBUG "glu32;opengl32"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/glew32d.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS GLEW::glew )
list(APPEND _IMPORT_CHECK_FILES_FOR_GLEW::glew "${_IMPORT_PREFIX}/lib/glew32d.lib" "${_IMPORT_PREFIX}/bin/glew32d.dll" )

# Import target "GLEW::glewmx" for configuration "Debug"
set_property(TARGET GLEW::glewmx APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(GLEW::glewmx PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/glew32mxd.lib"
  IMPORTED_LINK_INTERFACE_LIBRARIES_DEBUG "glu32;opengl32"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/glew32mxd.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS GLEW::glewmx )
list(APPEND _IMPORT_CHECK_FILES_FOR_GLEW::glewmx "${_IMPORT_PREFIX}/lib/glew32mxd.lib" "${_IMPORT_PREFIX}/bin/glew32mxd.dll" )

# Import target "GLEW::glew_s" for configuration "Debug"
set_property(TARGET GLEW::glew_s APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(GLEW::glew_s PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "C"
  IMPORTED_LINK_INTERFACE_LIBRARIES_DEBUG "glu32;opengl32"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libglew32d.lib"
  )

list(APPEND _IMPORT_CHECK_TARGETS GLEW::glew_s )
list(APPEND _IMPORT_CHECK_FILES_FOR_GLEW::glew_s "${_IMPORT_PREFIX}/lib/libglew32d.lib" )

# Import target "GLEW::glewmx_s" for configuration "Debug"
set_property(TARGET GLEW::glewmx_s APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(GLEW::glewmx_s PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "C"
  IMPORTED_LINK_INTERFACE_LIBRARIES_DEBUG "glu32;opengl32"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libglew32mxd.lib"
  )

list(APPEND _IMPORT_CHECK_TARGETS GLEW::glewmx_s )
list(APPEND _IMPORT_CHECK_FILES_FOR_GLEW::glewmx_s "${_IMPORT_PREFIX}/lib/libglew32mxd.lib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
