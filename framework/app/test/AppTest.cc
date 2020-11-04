#include "app.h"

#include <gmock/gmock.h>
using ::testing::Eq;

#include <gtest/gtest.h>
using ::testing::Test;

/***
 * 	\brief	Test fixture
 */
class appTest : public Test {
public:
	Application	TestApp;		// test application instance
protected:
	appTest(){}
	~appTest(){}

	virtual void SetUp(){}
	virtual void TearDown(){}
};

TEST_F (appTest, AppStoresPassedAppNameDefault) {
	// build command line for testing
	const char 	*argv[] = {"./AppTest"};
	int 		argc	= (int)(sizeof(argv)/sizeof(const char 	*));

	auto ExpAppName = std::string{"MyApp"};
	TestApp.parseCmdLineOptions(argc, argv);
	auto AppName	= TestApp.getAppName();

	EXPECT_STREQ(ExpAppName.c_str(), AppName.c_str());
}

TEST_F (appTest, AppStoresPassedAppNameLongArg) {
	// build command line for testing
	const char 	*argv[] = {"./AppTest", "--name", "MySuperLongApp"};
	int 		argc	= (int)(sizeof(argv)/sizeof(const char 	*));

	auto ExpAppName = std::string{"MySuperLongApp"};
	TestApp.parseCmdLineOptions(argc, argv);
	auto AppName	= TestApp.getAppName();

	EXPECT_STREQ(ExpAppName.c_str(), AppName.c_str());
}

TEST_F (appTest, AppStoresPassedAppNameShortArg) {
	// build command line for testing
	const char 	*argv[] = {"./AppTest", "-n", "MyShortApp"};
	int 		argc	= (int)(sizeof(argv)/sizeof(const char 	*));

	auto ExpAppName = std::string{"MyShortApp"};
	TestApp.parseCmdLineOptions(argc, argv);
	auto AppName	= TestApp.getAppName();

	EXPECT_STREQ(ExpAppName.c_str(), AppName.c_str());
}
