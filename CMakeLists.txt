cmake_minimum_required(VERSION 3.4 FATAL_ERROR)
project(demangle)
set( version 1.1 )
set( CMAKE_INCLUDE_CURRENT_DIR ON )

##
# DEMANGLE_CUSTOM_NAMESPACE - set to true if you want 
# to set your own custom namespace.
##
mark_as_advanced( DEMANGLE_CUSTOM_NAMESPACE )
if( NOT DEFINED DEMANGLE_CUSTOM_NAMESPACE )
set( DEMANGLE_CUSTOM_NAMESPACE 
        false 
        CACHE 
        BOOL 
        "Wrap the demangle call in a custom namespace using -DDEMANGLE_NAMESPACE=\"namespace\" when configuring cmake." )
endif()

##
# DEMANGLE_NAMESPACE - this is the actual namespace
# that you want to inject.
##
mark_as_advanced( DEMANGLE_NAMESPACE )

if( NOT DEFINED DEMANGLE_NAMESPACE )
set( DEMANGLE_NAMESPACE "" CACHE STRING "Namespace to inject" )
endif()

if( DEMANGLE_CUSTOM_NAMESPACE )
message (STATUS "Injecting the following namespace into your libdemangle build: ${DEMANGLE_NAMESPACE}" )
add_definitions( "-DINJECT_DEMANGLE_NAMESPACE=1" )
add_definitions( "-DDEMANGLE_NAMESPACE=${DEMANGLE_NAMESPACE}" )
endif( DEMANGLE_CUSTOM_NAMESPACE )

include_directories ( ${PROJECT_SOURCE_DIR} )
include_directories ( ${PROJECT_SOURCE_DIR}/include )
add_subdirectory( src )

mark_as_advanced( BUILD_TESTS )
set( BUILD_TESTS true CACHE BOOL "Tests build target available if true" )
if( BUILD_TESTS )
##
# Set up unit tests
##
enable_testing()
add_subdirectory( testsuite )
endif( BUILD_TESTS )
