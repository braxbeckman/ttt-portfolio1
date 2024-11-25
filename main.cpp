#include "board.hpp"
#include "console.hpp"
#include "game_state.hpp"
#include "player.hpp"
#include "swarm.hpp"
#include "game.hpp"
#include <cstdlib>
#include <iostream>

int main()
{
  Board *board = new Board;
  Console console(board);
  GameState gameState(board);
  Swarm swarm(board);


  int gameChoice{};
  std::cout << "Welcome to TTT! First question - would you like to play Normal TTT (1) or Battle TTT (2)? ";
  while (true)
  {
    std::cin >> gameChoice;
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
    Game TTT(&console, board, &gameState);
    TTT.playTTT();
  }
  else if (gameChoice == 2)
  {
    Game battle(&console, board, &gameState);
    battle.setPlayerOne(battle.selectClass());
    battle.setPlayerTwo(battle.selectClass());

    battle.playBattle();
  }
}

