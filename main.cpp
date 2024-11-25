#include "board.hpp"
#include "console.hpp"
#include "game_state.hpp"
#include "player.hpp"
#include "swarm.hpp"
#include "game.hpp"
#include "base_player.hpp"
#include <cstdlib>
#include <iostream>

int main()
{

  // Swarm swarm(board);
  bool replay{true};

bool getReplay();

  while(replay)
  {
  Board *board = new Board;
  Console console(board);
  GameState gameState(board);
    int gameChoice{};
    std::cout << "Welcome to TTT! First question - would you like to play Normal TTT (1) or Battle TTT (2)? ";
    while (true)
    {
      std::cin >> gameChoice;
      if (std::cin.fail())
      {
        std::cin.ignore(1000000, '\n');
        std::cin.clear();
        std::cout << "Please enter a valid choice ";
      }
      if (gameChoice > 2 || gameChoice < 1)
      {
        std::cout << "Please enter a valid choice ";
      }
      else
      {
        break;
      }
    }


    if (gameChoice == 1)
    {
      basePlayer playerOne(board, 'X');
      basePlayer playerTwo(board, 'O');
      
      Game TTT(&console, board, &gameState, &playerOne, &playerTwo);
      TTT.playTTT();
    }
    else if (gameChoice == 2)
    {
      Game battle(&console, board, &gameState);
      battle.setPlayerOne(battle.selectClass());
      battle.setPlayerTwo(battle.selectClass());

      battle.playBattle();
    }

    std::cout << "Would you like to play again? (Y to play again, any other character to quit) ";
    replay = getReplay();
  }
}

bool getReplay()
{
  fflush(stdin);
  char playAgain{'n'};

  while (true)
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