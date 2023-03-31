#include <gtest/gtest.h>
#include "../include/core.h"

TEST(SayHelloTest, BasicAssertions)
{
  std::string msg = Boilerplate::sayHello("John");
  EXPECT_EQ(msg, "Hello John");
}

TEST(IsOddFunctionTest, ShouldReturnTrue)
{
  int x = 2;
  EXPECT_TRUE(Boilerplate::isOdd(x));
}

TEST(IsOddFunctionTest, ShouldReturnFalse)
{
  int x = 1;
  EXPECT_FALSE(Boilerplate::isOdd(x));
}
