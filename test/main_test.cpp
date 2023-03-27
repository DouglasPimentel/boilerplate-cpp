#include <gtest/gtest.h>
#include "../include/core.h"

TEST(SayHelloTest, BasicAssertions)
{
  std::string msg = Boilerplate::sayHello("John");
  EXPECT_EQ(msg, "Hello John");
}