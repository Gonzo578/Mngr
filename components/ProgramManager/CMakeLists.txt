# Component is compiled into a library
add_library(ProgramManager "")

#Add source files for target
target_sources(ProgramManager
	PRIVATE
		src/ProgramManager.cc
)

# Component include pathes
target_include_directories(ProgramManager
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}/includes
)

# Unit test configuration for ProgramManager component
set(ProgramManagerTest_SRC test/ProgramManagerTest.cc)
add_gmock_test(ProgramManagerTest ${ProgramManagerTest_SRC})
target_link_libraries(ProgramManagerTest ProgramManager)