#include "game.hpp"
#include "swarm.hpp"
#include "base_player.hpp"
#include <iostream>
#include <string>

void Game::playTTT()
{
  bool gameOver{false};

  while (!gameOver)
  {
    std::cout << console->displayBoard() << std::endl;
    std::cout << playerOne->getMark() << "! Your turn! ";
    board->takeTurn(playerOne->getInput(), playerOne->getMark());
    if (gameState->checkStatus() == WON)
    {
      std::cout << gameState->getWinner() << " has won!" << std::endl;
      break;
    }
    if (gameState->checkStatus() == TIE)
    {
      std::cout << "Game ended in a tie!" << std::endl;
      break;
    }


    std::cout << console->displayBoard() << std::endl;
    std::cout << playerTwo->getMark() << "! Your turn! ";
    board->takeTurn(playerTwo->getInput(), playerTwo->getMark());
    if (gameState->checkStatus() == WON)
    {
      std::cout << gameState->getWinner() << " has won!" << std::endl;
      break;
    }
    std::cout << console->displayBoard() << std::endl;
    
  }
}

void Game::playBattle()
{
    std::cout << "Battle TTT Game started!" << std::endl;
}

void Game::setPlayerOne(Player *player)
{
    playerOne = player;
}
void Game::setPlayerTwo(Player *player)
{
    playerTwo = player;
}

Player *Game::selectClass()
{
std::string choice{};
std::cout << "Would you like to play \"The Swarm\" (1) or \"The Pyromancer\" (2)? ";

while (true)
{
    std::cin.clear();
    std::cin.ignore(1000000000, '\n');
    
    fflush(stdin);
    getline(std::cin, choice);
    if (choice.length() > 1)
    {
        std::cout << "Please enter 1 or 2: ";
    }
    else if (choice[0] != (int) choice[0])
    {
        std::cout << "Please enter either 1 or 2: ";
    }
    else 
    {
        std::cout << "success!";
        if (choice[0] == '1')
        {
            Swarm *player = new Swarm(board);
            return player;
        }
        std::cout << "fail(?)!" << std::endl;
    }
}
}

bool Game::getReplay()
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

Game::Game(Console *console, Board *board, GameState *gameState)
{
  this->console = console;
  this->board = board;
  this-> gameState = gameState;
}

Game::Game(Console *console, Board *board, GameState *gameState, Player *playerOne, Player *playerTwo)
{
  this->console = console;
  this->board = board;
  this-> gameState = gameState;
  this->playerOne = playerOne;
  this->playerTwo = playerTwo;
}