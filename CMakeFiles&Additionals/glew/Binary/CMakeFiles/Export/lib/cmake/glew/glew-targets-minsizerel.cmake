#----------------------------------------------------------------
# Generated CMake target import file for configuration "MinSizeRel".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "GLEW::glew" for configuration "MinSizeRel"
set_property(TARGET GLEW::glew APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
set_target_properties(GLEW::glew PROPERTIES
  IMPORTED_IMPLIB_MINSIZEREL "${_IMPORT_PREFIX}/lib/glew32.lib"
  IMPORTED_LINK_INTERFACE_LIBRARIES_MINSIZEREL "glu32;opengl32"
  IMPORTED_LOCATION_MINSIZEREL "${_IMPORT_PREFIX}/bin/glew32.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS GLEW::glew )
list(APPEND _IMPORT_CHECK_FILES_FOR_GLEW::glew "${_IMPORT_PREFIX}/lib/glew32.lib" "${_IMPORT_PREFIX}/bin/glew32.dll" )

# Import target "GLEW::glewmx" for configuration "MinSizeRel"
set_property(TARGET GLEW::glewmx APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
set_target_properties(GLEW::glewmx PROPERTIES
  IMPORTED_IMPLIB_MINSIZEREL "${_IMPORT_PREFIX}/lib/glew32mx.lib"
  IMPORTED_LINK_INTERFACE_LIBRARIES_MINSIZEREL "glu32;opengl32"
  IMPORTED_LOCATION_MINSIZEREL "${_IMPORT_PREFIX}/bin/glew32mx.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS GLEW::glewmx )
list(APPEND _IMPORT_CHECK_FILES_FOR_GLEW::glewmx "${_IMPORT_PREFIX}/lib/glew32mx.lib" "${_IMPORT_PREFIX}/bin/glew32mx.dll" )

# Import target "GLEW::glew_s" for configuration "MinSizeRel"
set_property(TARGET GLEW::glew_s APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
set_target_properties(GLEW::glew_s PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_MINSIZEREL "C"
  IMPORTED_LINK_INTERFACE_LIBRARIES_MINSIZEREL "glu32;opengl32"
  IMPORTED_LOCATION_MINSIZEREL "${_IMPORT_PREFIX}/lib/libglew32.lib"
  )

list(APPEND _IMPORT_CHECK_TARGETS GLEW::glew_s )
list(APPEND _IMPORT_CHECK_FILES_FOR_GLEW::glew_s "${_IMPORT_PREFIX}/lib/libglew32.lib" )

# Import target "GLEW::glewmx_s" for configuration "MinSizeRel"
set_property(TARGET GLEW::glewmx_s APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
set_target_properties(GLEW::glewmx_s PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_MINSIZEREL "C"
  IMPORTED_LINK_INTERFACE_LIBRARIES_MINSIZEREL "glu32;opengl32"
  IMPORTED_LOCATION_MINSIZEREL "${_IMPORT_PREFIX}/lib/libglew32mx.lib"
  )

list(APPEND _IMPORT_CHECK_TARGETS GLEW::glewmx_s )
list(APPEND _IMPORT_CHECK_FILES_FOR_GLEW::glewmx_s "${_IMPORT_PREFIX}/lib/libglew32mx.lib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
