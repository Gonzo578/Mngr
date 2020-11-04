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

TEST_F (appTest, AppStoresName) {
	auto ExpAppName = std::string{"MyApp"};
	auto AppName	= TestApp.getAppName();
	EXPECT_STREQ(ExpAppName.c_str(), AppName.c_str());
}
