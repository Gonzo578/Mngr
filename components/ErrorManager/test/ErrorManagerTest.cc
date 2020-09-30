#include "ErrorManager.h"

#include <gmock/gmock.h>
using ::testing::Eq;

#include <gtest/gtest.h>
using ::testing::Test;
using namespace testing;

namespace ErrorManager {
class ErrorManagerFixture: public Test {
public:
	ErrorManager ErrMngr;
};

TEST_F(ErrorManagerFixture, ReturnsOne) {
	EXPECT_THAT(ErrMngr.PrintHelloErrorManager(), Eq(1));
}
}
