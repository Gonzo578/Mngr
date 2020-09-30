# Component is compiled into a library
add_library(ErrorManager "")

#Add source files for target
target_sources(ErrorManager
	PRIVATE
		src/ErrorManager.cc
)

# Component include pathes
target_include_directories(ErrorManager
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}/includes
)

# Unit test configuration for ErrorManager component
set(ErrorManagerTest_SRC test/ErrorManagerTest.cc)
add_gmock_test(ErrorManagerTest ${ErrorManagerTest_SRC})
target_link_libraries(ErrorManagerTest ErrorManager)