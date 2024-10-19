#include "board.hpp"
#include "console.hpp"
#include "game_state.hpp"
#include "validator.hpp"
#include <cstdlib>
#include <iostream>

bool replay{true};
int player{};
bool intro{true};

int main()
{
  while (replay == true)
  {
    Board *board = new Board;
    Console console(board);
    GameState gameState(board);
    Validator validator(board);
    replay = false;
    int counter{0};
    char symbol{'X'};

    while (gameState.checkStatus() == "playing")
    {
      if (counter == 9)
      {
        break;
      }

      counter % 2 ? symbol = 'O' : symbol = 'X';
      counter % 2 ? player = 2 : player = 1;

      std::cout << "\033[2J\033[1;1H" << (intro ? "Welcome to TTT!\n" : "") << console.displayBoard();
      intro = false;

      std::cout << "Player " << player << ", where would you like to move? (1-9) ";
      int move{validator.getInput()};
      board->takeTurn(move, symbol);

      counter++;
    }
    if (counter == 9)
    {
      std::cout << "It's a draw!\n Would you like to play again? (Y to continue, any other key to quit) ";
      replay = validator.getReplay();
      continue;
    }


      std::cout << console.displayBoard();
      std::cout << "The game is over, " << gameState.getWinner() << " won!\n";

      std::cout << "Would you like to play again? (Y to continue, any other key to quit) ";
      replay = validator.getReplay();
  }

  std::cout << "Thank you for playing! Come again!" << std::endl;
}
