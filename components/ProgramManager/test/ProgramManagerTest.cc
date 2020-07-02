#include "ProgramManager.h"

#include <gmock/gmock.h>
using ::testing::Eq;

#include <gtest/gtest.h>
using ::testing::Test;


TEST (ProgramManager, ReturnsOne) {
	EXPECT_THAT(PrintHelloProgramManager(), Eq(1));
}
