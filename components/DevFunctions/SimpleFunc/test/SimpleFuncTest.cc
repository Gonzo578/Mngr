/*
 * ToDoTest.cc
 *
 *  Created on: 14.11.2017
 *      Author: gonzo
 */


#include "SimpleFunc.h"

#include <gmock/gmock.h>
using ::testing::Eq;

#include <gtest/gtest.h>
using ::testing::Test;

namespace DevFunctions{
namespace testing {

class SimpleFuncTest : public Test {
protected:
	SimpleFuncTest(){}
	~SimpleFuncTest(){}

	virtual void SetUp(){}
	virtual void TearDown(){}

	SimpleFunc fct;
};


TEST_F(SimpleFuncTest, SimpleFunc_returns_One) {
	EXPECT_THAT(fct.HelloSimpleFunc(), Eq(1));
}

} // namespace testing
} // namespace DevFunctions
