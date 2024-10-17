#include "validator.hpp"
#include <iostream>

int Validator::getInput()
{
  int input{};
  bool valid{false};
  while (valid == false)
  {
    std::cout << "Please enter where you'd like to move (1-9): ";
    std::cin >> input;
    if (std::cin.fail())
    {
      std::cin.ignore(1000000000000000000, '\n');
      std::cin.clear();
      std::cout << "\nInvalid Input\n";
    }
    else if (input > 9 || input < 0)
    {
      std::cout << "The number you enterd is outside the range of 1-9";
    }
    else
    {
      valid = true;
    }
  }
  return input;
}
