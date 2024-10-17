#include "board.hpp"
#include "console.hpp"
#include "game_state.hpp"
#include "validator.hpp"
#include <cstdlib>
#include <iostream>

int main()
{
  Board board;
  Console console(&board);
  GameState gameState(&board);
  Validator validator;

  int counter{};
  while (gameState.checkStatus() != "won")
  {
    counter++;
    std::cout << console.displayBoard();
    std::cout << "Where would you like to move?";
    int move{validator.getInput()};
    board.takeTurn(move, 'X');
  }
}
