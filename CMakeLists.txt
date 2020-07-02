cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# Disable in-source builds to prevent source tree corruption.
if(" ${CMAKE_SOURCE_DIR}" STREQUAL " ${CMAKE_BINARY_DIR}")
    message(FATAL_ERROR "
            FATAL: In-source builds are not allowed.
            You should create a separate directory for build files.
")
endif()

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
