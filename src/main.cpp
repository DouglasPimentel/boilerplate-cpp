#include <iostream>
#include <vector>
#include "../include/core.h"

int main(int argc, char **argv)
{
  std::vector<Boilerplate::S> persons{{"John Doe", "jonh@example.com", 25}};
  int x = 1;

  std::cout << Boilerplate::sayHello(persons[0].name) << std::endl;

  for (auto &person : persons)
  {
    std::cout << person.name << " " << person.email << " " << person.age << std::endl;
  }

  bool result_is_odd = Boilerplate::isOdd(x);

  if (result_is_odd)
  {
    std::cout << x << " is odd" << std::endl;
  }
  else
  {
    std::cout << x << " is even" << std::endl;
  }

  return 0;
}