#include "src/lib/cpplib.h"

#include <map>
#include <vector>

#include "gtest/gtest.h"


TEST(FindMaxTest, FindMaxHandlesSizeOne) {
  CPPLib cpplib;
  std::vector<int> inputs = {2};
  EXPECT_EQ(cpplib.FindMax(inputs), 2);
  // other stuff
}

TEST(FindMaxTest, FindMaxHandlesConsecutiveNumbers) {
  CPPLib cpplib;
  std::vector<int> inputs = {1, 2, 3, 4};
  EXPECT_EQ(cpplib.FindMax(inputs), 4);
}

TEST(FindMaxTest, FindMaxHandlesEmptyVector) {
  CPPLib cpplib;
  std::vector<int> inputs = {};
  EXPECT_EQ(cpplib.FindMax(inputs), -1);
}

