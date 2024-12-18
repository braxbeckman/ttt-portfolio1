#include "game.hpp"
#include "swarm.hpp"
#include "pyromancer.hpp"
#include "base_player.hpp"
#include "stat_tracker.hpp"
#include <iostream>
#include <string>

void Game::playTTT()
{
  bool gameOver{false};
  std::cout << console->displayBoard() << std::endl;

  while (!gameOver)
  {
    std::cout << playerOne->getMark() << "! Your turn! ";
    board->takeTurn(playerOne->getInput(), playerOne->getMark());
    if (gameState->checkStatus() == WON)
    {
      std::cout << console->displayBoard() << std::endl;
      std::cout << gameState->getWinner() << " has won!" << std::endl;

      if (gameState->getWinner() == 'X')
      {
        std::cout << "testx" << std::endl;
        tracker->logXWin();
      }
      else if (gameState->getWinner() == 'O')
      {
        std::cout << "testo" << std::endl;
        tracker->logOWin();
      }

      break;
    }
    if (gameState->checkStatus() == TIE)
    {
      std::cout << console->displayBoard() << std::endl;
      std::cout << "Game ended in a tie!" << std::endl;
      tracker->logTie();
      break;
    }


    std::cout << console->displayBoard() << std::endl;
    std::cout << playerTwo->getMark() << "! Your turn! ";
    board->takeTurn(playerTwo->getInput(), playerTwo->getMark());
    if (gameState->checkStatus() == WON)
    {
      std::cout << gameState->getWinner() << " has won!" << std::endl;
      if (gameState->getWinner() == 'X')
      {
        std::cout << "testx" << std::endl;
        tracker->logXWin();
      }
      else if (gameState->getWinner() == 'O')
      {
        std::cout << "testo" << std::endl;
        tracker->logOWin();
      }
      break;
    }
    std::cout << console->displayBoard() << std::endl;
  }
}

void Game::playBattle()
{
  bool gameOver{false};
  std::cout << console->displayBoard();

  while (!gameOver)
  {
    std::cout << playerOne->getMark() << "! Your turn! ";
    board->takeTurn(playerOne->getInput(), playerOne->getMark());
    if (gameState->checkStatus(playerOne) == WON)
    {
      std::cout << console->displayBoard() << std::endl;
      std::cout << gameState->getWinner() << " has won!" << std::endl;
      if (gameState->getWinner() == 'X')
      {
        tracker->logXWin();
      }
      else if (gameState->getWinner() == 'O')
      {
        tracker->logOWin();
      }
      break;
    }
    if (gameState->checkStatus(playerOne) == TIE)
    {
      std::cout << console->displayBoard() << std::endl;
      std::cout << "Game ended in a tie!" << std::endl;
      tracker->logTie();
      break;
    }


    std::cout << console->displayBoard() << std::endl;
    std::cout << playerTwo->getMark() << "! Your turn! ";
    board->takeTurn(playerTwo->getInput(), playerTwo->getMark());
    if (gameState->checkStatus(playerTwo) == WON)
    {
      std::cout << gameState->getWinner() << " has won!" << std::endl;
      if (gameState->getWinner() == 'X')
      {
        tracker->logXWin();
      }
      else if (gameState->getWinner() == 'O')
      {
        tracker->logOWin();
      }
      break;
    }
    if (gameState->checkStatus(playerTwo) == TIE)
    {
      std::cout << console->displayBoard() << std::endl;
      std::cout << "Game ended in a tie!" << std::endl;
      tracker->logTie();
      break;
    }
    std::cout << console->displayBoard() << std::endl;
  }
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
std::cout << "\033[2J" << "Would you like to play \"The Swarm\" or \"The Pyromancer\"?";
std::cout << "\n(1) The Swarm - Overwhelm your foes with as-of-yet unseen battle tactics (win if your mark is in all 4 corners)" << std::endl;
std::cout << "\n(2) The Pyromancer - Tap into the weave and unleash a destructive force even you are not safe from (has an ability that can be used to wipe the board once per game)" << std::endl;

while (true)
{
    fflush(stdin);
    getline(std::cin, choice);
    fflush(stdin);
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
      // std::cout << "success!";
      if (choice[0] == '1')
      {
        Swarm *tmpPlayer = new Swarm(board, 'X');
        return tmpPlayer;
      }
      if (choice[0] == '2')
      {
        Pyromancer *tmpPlayer = new Pyromancer(board, 'O');
        return tmpPlayer;
      }
      // std::cout << "fail(?)!" << std::endl;
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

Game::Game(Console *console, Board *board, GameState *gameState, StatTracker *tracker)
{
  this->console = console;
  this->board = board;
  this-> gameState = gameState;
  this->tracker = tracker;
}

Game::Game(Console *console, Board *board, GameState *gameState, Player *playerOne, Player *playerTwo, StatTracker *tracker)
{
  this->console = console;
  this->board = board;
  this-> gameState = gameState;
  this->playerOne = playerOne;
  this->playerTwo = playerTwo;
  this->tracker = tracker;
}