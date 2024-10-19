#include "validator.hpp"
#include <iostream>

Validator::Validator(Board *board)
{
  this->board = board;
}

int Validator::getInput()
{
  double input{};
  bool valid{false};
  while (valid == false)
  {
    std::cin >> input;

    // std::cout << "Row: " << (input - 1) / 3 << "\nColumn: " << (input - 1) % 3 << std::endl;

    if (std::cin.fail())
    {
      std::cin.clear();
      std::cin.ignore(1000000000000000000, '\n');
      std::cout << "Invalid input, please enter a number 1-9: ";
    }
    else if(input != (int) input)
    {
      std::cout << "Invalid input, please enter a non-decimal number 1-9: ";
    }
    else if (input > 9 || input < 0)
    {
      std::cout << "The number you enterd is outside the range of 1-9\n";
    }
    else if (board->getMark((input - 1) / 3, ((int) input - 1) % 3) == 'X' ||
              board->getMark((input - 1) / 3, ((int) input - 1) % 3) == 'O')
    {
      std::cout << "This space is already occupied, please pick another.\n";
    }
    else
    {
      valid = true;
    }
    std::cin.clear();
  }
  // std::cout << "Row: " << (input - 1) / 3 << "\nColumn: " << (input - 1) % 3 << std::endl;
  return input;
}

bool Validator::getReplay()
{
  bool valid{false};
  char playAgain{false};

  while (!valid)
  {

    std::cin >> playAgain;
    if (std::cin.fail())
    {
      std::cin.clear();
      std::cin.ignore(1000000000000000000, '\n');
      std::cout << "Invalid input, please enter either \'Y\' or another character\n";
    }
    else if (tolower(playAgain) == 'y')
    {
      return true;
      std::cout << "Invalid input, please enter either \'Y\' or another character.\n";
    }
    else
    {
      return false;
    }
  }
  return false;
}
