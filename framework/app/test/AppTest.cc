#include "app.h"

#include <gmock/gmock.h>
using ::testing::Eq;

#include <gtest/gtest.h>
using ::testing::Test;

/***
 * 	\brief	Test fixture
 */
class appTest : public Test {
protected:
	appTest(){}
	~appTest(){}

	virtual void SetUp(){}
	virtual void TearDown(){}
};

TEST_F (appTest, AppStoresName) {
	auto str1 = std::string{"Hallo"};
	auto str2= std::string{"Hallo"};
	EXPECT_STREQ(str1.c_str(),str2.c_str());
}
