#include "app.h"

#include <gmock/gmock.h>
using ::testing::Eq;

#include <gtest/gtest.h>
using ::testing::Test;

using namespace framework;

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


/**************************************************************************************************
 * 	Command line parameter: "--name"
 * */
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

/**************************************************************************************************
 * 	Command line parameter: "--root"
 * */
TEST_F (appTest, AppStoresPassedAppRootNodeDefault) {
	// build command line for testing
	const char 	*argv[] = {"./AppTest"};
	int 		argc	= (int)(sizeof(argv)/sizeof(const char 	*));

	auto ExpRootNodeName = std::string{"root"};
	TestApp.parseCmdLineOptions(argc, argv);
	auto RootNodeName	= TestApp.getRootNodePath();

	EXPECT_STREQ(ExpRootNodeName.c_str(), RootNodeName.c_str());
}

TEST_F (appTest, AppStoresPassedAppRootNodeLongArg) {
	// build command line for testing
	const char 	*argv[] = {"./AppTest", "--root", "MyLongRootNode"};
	int 		argc	= (int)(sizeof(argv)/sizeof(const char 	*));

	auto ExpRootNodeName = std::string{"MyLongRootNode"};
	TestApp.parseCmdLineOptions(argc, argv);
	auto RootNodeName	= TestApp.getRootNodePath();

	EXPECT_STREQ(ExpRootNodeName.c_str(), RootNodeName.c_str());
}

TEST_F (appTest, AppStoresPassedAppRootNodeShortArg) {
	// build command line for testing
	const char 	*argv[] = {"./AppTest", "-r", "MyShortRootNode"};
	int 		argc	= (int)(sizeof(argv)/sizeof(const char 	*));

	auto ExpRootNodeName = std::string{"MyShortRootNode"};
	TestApp.parseCmdLineOptions(argc, argv);
	auto RootNodeName	= TestApp.getRootNodePath();

	EXPECT_STREQ(ExpRootNodeName.c_str(), RootNodeName.c_str());
}

/**************************************************************************************************
 * 	Command line parameter: "--node"
 * */
TEST_F (appTest, AppStoresPassedNodeNameDefault) {
	// build command line for testing
	const char 	*argv[] = {"./AppTest"};
	int 		argc	= (int)(sizeof(argv)/sizeof(const char 	*));

	auto ExpNodeName = std::string{"ECU"};
	TestApp.parseCmdLineOptions(argc, argv);
	auto NodeName	= TestApp.getNodeName();

	EXPECT_STREQ(ExpNodeName.c_str(), NodeName.c_str());
}

TEST_F (appTest, AppStoresPassedNodeNameLongArg) {
	// build command line for testing
	const char 	*argv[] = {"./AppTest", "--node", "ECU1"};
	int 		argc	= (int)(sizeof(argv)/sizeof(const char 	*));

	auto ExpNodeName = std::string{"ECU1"};
	TestApp.parseCmdLineOptions(argc, argv);
	auto NodeName	= TestApp.getNodeName();

	EXPECT_STREQ(ExpNodeName.c_str(), NodeName.c_str());
}

TEST_F (appTest, AppStoresPassedNodeNameShortArg) {
	// build command line for testing
	const char 	*argv[] = {"./AppTest", "-e", "ECU2"};
	int 		argc	= (int)(sizeof(argv)/sizeof(const char 	*));

	auto ExpNodeName = std::string{"ECU2"};
	TestApp.parseCmdLineOptions(argc, argv);
	auto NodeName	= TestApp.getNodeName();

	EXPECT_STREQ(ExpNodeName.c_str(), NodeName.c_str());
}
