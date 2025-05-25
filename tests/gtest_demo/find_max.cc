#include <vector>

#include "gtest/gtest.h"

int FindMax(std::vector<int> &inputs) {
  if (inputs.size() == 0) {
    return -1;
  }
  int result = -10000;
  for (auto n : inputs) {
    if (n > result) {
      result = n;
    }
  }
  return result;
}

TEST(FindMax, SortedNumbers) {
  std::vector<int> inputs = {1, 2, 3, 4};
  EXPECT_EQ(FindMax(inputs), 4);
}

TEST(FindMax, EmptyVector) {
  std::vector<int> inputs = {};
  EXPECT_EQ(FindMax(inputs), -1);
}

TEST(FindMax, Size1) {
  std::vector<int> inputs = {10};
  EXPECT_EQ(FindMax(inputs), 10);
}

TEST(FindMax, LargeSize) {
  std::vector<int> inputs = {1, 2, 4, 5, 3, 8, 100, 1000, 2, 4, 56, 76, 54};
  EXPECT_EQ(FindMax(inputs), 1000);
  EXPECT_TRUE(FindMax(inputs) == 1000);
}

TEST(FindMax, AllZeros) {
  std::vector<int> inputs = {
      0, 0, 0, 0, 0, 0, 0,
  };

  EXPECT_EQ(FindMax(inputs), 0);
}
