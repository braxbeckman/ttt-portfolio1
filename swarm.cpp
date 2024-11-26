#include "swarm.hpp"
#include <cctype>
#include <iostream>

Swarm::Swarm(Board *board, char mark)
{
  this->board = board;
  this->mark = mark;
}

int Swarm::getInput()
{
  fflush(stdin);
  std::string input{};
  // bool valid{false};

  while (true)
  {
    fflush(stdin);
    std::cin >> input;

    // std::cout << "Row: " << (input - 1) / 3 << "\nColumn: " << (input - 1) % 3 << std::endl;

    if (std::cin.fail())
    {
      std::cin.clear();
      std::cin.ignore(1000000000000000000, '\n');
      std::cout << "Invalid input, please enter a number 1-9: ";
    }
    // else if (input[0] == 'a' && input.length() == 1)
    // {
    //   std::cout << "using an ability" << std::endl;
    // }
    // else if (input[0] == 'a' && input.length() > 1)
    // {
    //   std::cout << "Please enter either \'a\' or a number 1-9" << std::endl;
    // }
    // else if (input[0] != 'a' && isalpha(input[0]))
    // {
    //   std::cout << "Please enter either \'a\' or a number 1-9" << std::endl;
    // }
    else if (stod(input) != stoi(input))
    {
      std::cout << "Invalid input, please enter a non-decimal number 1-9: ";
    }
    else if (stoi(input) > 9 || stoi(input) < 1)
    {
      std::cout << "The number you enterd is outside the range of 1-9\n";
    }
    else if (board->getMark((stoi(input) - 1) / 3, (stoi(input) - 1) % 3) == 'X' ||
             board->getMark((stoi(input) - 1) / 3, (stoi(input) - 1) % 3) == 'O')
    {
      std::cout << "This space is already occupied, please pick another.\n";
    }
    else
    {
      break;
    }
  }
  fflush(stdin);
  std::cin.clear();
  // std::cout << "Row: " << (input - 1) / 3 << "\nColumn: " << (input - 1) % 3 << std::endl;
  return stoi(input);
}

void Swarm::test()
{
  std::cout << "test succeeded!" << std::endl;
}

char Swarm::getMark()
{
  return mark;
}

std::string Swarm::getArchetype()
{
    return archetype;
}