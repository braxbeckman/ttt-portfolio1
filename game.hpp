#pragma once
#include "board.hpp"
#include "console.hpp"
#include "game_state.hpp"
#include "player.hpp"

class Game
{
private:
  Console *console;
  Board *board;
  GameState *gameState;
  Player *playerOne;
  Player *playerTwo;

public:
  Game(Console *console, Board *board, GameState *gameState);
  void setPlayerOne(Player *player);
  void setPlayerTwo(Player *player);
  Player *selectClass();
  bool getReplay();
  void playTTT();
  void playBattle();
};
