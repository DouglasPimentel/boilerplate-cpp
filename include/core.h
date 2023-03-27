#ifndef BOILERPLATE_CPP_CORE_H
#define BOILERPLATE_CPP_CORE_H

#include <string>

namespace Boilerplate
{
  struct S
  {
    std::string name;
    std::string email;
    int age;
    S(std::string name, std::string email, int age) : name(name), email(email), age(age) {}
  };

  std::string sayHello(std::string name);

  bool isOdd(int x);
}

#endif // BOILERPLATE_CPP_CORE_H