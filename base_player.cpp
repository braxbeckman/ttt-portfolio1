#include "base_player.hpp"
#include <iostream>


basePlayer::basePlayer(Board *board, char mark)
{
    this->board = board;
    this->mark = mark;
}


int basePlayer::getInput()
{
  fflush(stdin);
  std::string input{};

  std::cout << "Please select what square you would like to play: ";

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
    else if (isalpha(input[0]))
    {
        std::cout << "Invalid input, please enter a number 1-9: ";
    }
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

void basePlayer::test()
{
    std::cout << "test succesful!" << std::endl;
}

char basePlayer::getMark()
{
    return mark;
}