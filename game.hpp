#pragma once
#include "board.hpp"
#include "console.hpp"
#include "game_state.hpp"
#include "player.hpp"
#include "stat_tracker.hpp"

class Game
{
private:
  Console *console;
  Board *board;
  GameState *gameState;
  Player *playerOne;
  Player *playerTwo;
  StatTracker *tracker;

public:
  Game(Console *console, Board *board, GameState *gameState, StatTracker *tracker);
  Game(Console *console, Board *board, GameState *gameState, Player *playerOne, Player *playerTwo, StatTracker *tracker);

  void setPlayerOne(Player *player);
  void setPlayerTwo(Player *player);
  Player *selectClass();
  bool getReplay();
  void playTTT();
  void playBattle();
};
