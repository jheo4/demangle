set( CMAKE_INCLUDE_CURRENT_DIR ON )

add_library( demangle SHARED demangle.cpp )

install( TARGETS demangle
         ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib )
