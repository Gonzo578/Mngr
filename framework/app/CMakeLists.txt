# Component is compiled into a library
add_library(App "")

# Add boost to includes
find_package(Boost REQUIRED program_options)

#Add source files for target
target_sources(App
	PRIVATE
		src/app.cc
)

# Component include pathes
target_include_directories(App
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}/includes
	PRIVATE
		${Boost_INCLUDE_DIRS}
)

target_link_libraries(App
	PRIVATE
		${Boost_LIBRARIES}
)

# Unit test configuration for Application component
set(AppTest_SRC test/AppTest.cc)
add_gmock_test(AppTest ${AppTest_SRC})
target_link_libraries(AppTest App ${Boost_LIBRARIES})