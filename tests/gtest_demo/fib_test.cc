#include <map>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"
using ::testing::Lt;

// Calculates the n'th Fib number.
// Returns a negative value if the input is negative.
// 1, 1, 2, 3, 5, 8, 13, ..., Fib(1,000,000)
int Fib(int n) {
  // Base case
  if (n <= 1) {
    return n;
  }

  // Recursive relationship
  return Fib(n - 1) + Fib(n - 2);
}

TEST(FibTest, CanWorkCorrectlyForNonNegativeValues) {
  EXPECT_EQ(Fib(0), 0);

  EXPECT_EQ(Fib(1), 1);
  EXPECT_EQ(Fib(5), 5);
  EXPECT_EQ(Fib(6), 8) << "Error: The factorial calculation was wrong!";
}

TEST(FibTest, FirstFiveNonNegativeNumber) {
  EXPECT_EQ(Fib(0), 0);
  EXPECT_EQ(Fib(1), 1);
  EXPECT_EQ(Fib(2), 1);
  EXPECT_EQ(Fib(3), 2);
  EXPECT_EQ(Fib(4), 3);

  EXPECT_TRUE(Fib(4) == 3);
}

TEST(FibTest, OutputsZeroForNegativeInputs) {
  EXPECT_LT(Fib(-1), 0);
  EXPECT_LT(Fib(-10), 0);
  EXPECT_THAT(Fib(-10), Lt(0));
}
