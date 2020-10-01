# Component is compiled into a library
add_library(SimpleFunc "")

#Add source files for target
target_sources(SimpleFunc
	PRIVATE
		src/SimpleFunc.cc
)

# Component include pathes
target_include_directories(SimpleFunc
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}/includes
)

# Unit test configuration for SimpleFunc device function
set(SimpleFuncTest_SRC test/SimpleFuncTest.cc)
add_gmock_test(SimpleFuncTest ${SimpleFuncTest_SRC})
target_link_libraries(SimpleFuncTest SimpleFunc)