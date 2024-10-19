#include "game_state.hpp"
#include <string>

std::string GameState::checkStatus()
{
  for (int i = 0; i < 3; i++)
  {
    for (int k = 0; k < 3; k++)
    {
      if (board->getMark(i, k) == board->getMark(i, k + 1) && board->getMark(i, k) == board->getMark(i, k + 2))
      {
        winner = board->getMark(i, k);
        return "won";
      }
    }
  }
  for (int i = 0; i < 3; i++)
  {
    for (int k = 0; k < 3; k++)
    {
      if (board->getMark(i, k) == board->getMark(i + 1, k) && board->getMark(i, k) == board->getMark(i + 2, k))
      {
        winner = board->getMark(i, k);
        return "won";
      }
    }
  }
  if (((board->getMark(0, 0) == board->getMark(1, 1)) && (board->getMark(0, 0) == board->getMark(2, 2))) ||
      (((board->getMark(0, 2)) == board->getMark(1, 1)) && (board->getMark(0, 2) == board->getMark(2, 0))))
  {
    winner = board->getMark(1, 1);
    return "won";
  }
  else
  {
    return "playing";
  }
}

GameState::GameState(Board *board)
{
  winner = '\0';
  this->board = board;
}

char GameState::getWinner()
{
  return winner;
}
