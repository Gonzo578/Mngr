cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# Disable in-source builds to prevent source tree corruption.
if(" ${CMAKE_SOURCE_DIR}" STREQUAL " ${CMAKE_BINARY_DIR}")
    message(FATAL_ERROR "
            FATAL: In-source builds are not allowed.
            You should create a separate directory for build files.
")
endif()

# Configure general build options
option (BUILD_DOXY_DOC "Build doxygen documentation" ON)

# Check if doxygen is installed and if yes configure it
find_package(Doxygen)

if(DOXYGEN_FOUND)
	set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Docs)
    
    # request to configure the file
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message("Doxygen build started")
    
    # note the option ALL which allows to build the docs together with the application
    add_custom_target( doc_doxygen ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM )
else (DOXYGEN_FOUND)
  message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)

# Global project name
project ("ProgramManager")

# Add local module path to the cmake modules search path
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)

# Include local cmake modules
include(gmock)

# Testing configuration
enable_testing()

# Add components to projects build
add_subdirectory(components)

# Main project target configuration
add_executable (app "")

target_sources (app
	PRIVATE
		src/main.cc
)

# Target link libraries
target_link_libraries(app
	PRIVATE
		toDoCore
		printerCore
		ProgramManager
)
