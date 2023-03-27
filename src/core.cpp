#include "../include/core.h"

std::string Boilerplate::sayHello(std::string name)
{
  return "Hello " + name;
}

bool Boilerplate::isOdd(int x)
{
  if (x % 2 == 0)
    return true;

  return false;
}