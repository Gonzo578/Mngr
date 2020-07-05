cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

# Disable in-source builds to prevent source tree corruption.
if(" ${CMAKE_SOURCE_DIR}" STREQUAL " ${CMAKE_BINARY_DIR}")
    message(FATAL_ERROR "
            FATAL: In-source builds are not allowed.
            You should create a separate directory for build files.
")
endif()

# Configure general build options
option (BUILD_DOXY_DOC "Build doxygen documentation" ON)

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

#**************************************************************************************************
#* Doxygen configuration
#* Add a special target to generate API documentation with doxygen
#* We use the standard capabilities of CMake to create docs
#**************************************************************************************************
# Check if doxygen is installed and if yes configure it
find_package(Doxygen)

if(DOXYGEN_FOUND)
	# exclude external dependencies included in the project from doc generation
	set(DOXYGEN_EXCLUDE_PATTERNS
        */external/*
  	)
  	
	doxygen_add_docs(docs
    	${CMAKE_CURRENT_SOURCE_DIR}
    	WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    	COMMENT "Generating API documentation with Doxygen"
	)
else (DOXYGEN_FOUND)
  message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)