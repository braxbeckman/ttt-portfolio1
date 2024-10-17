#include "console.hpp"
#include <string>

using namespace std;

Console::Console(Board *board)
{
  this->board = board;
}
string Console::displayBoard()
{
  string output{};
  output += emptySpacer;
  output += board->getMark(0, 0);
  output += vertSeparator;
  output += board->getMark(0, 1);
  output += vertSeparator;
  output += board->getMark(0, 2);
  output += horizSeparator;
  output += emptySpacer;
  output += board->getMark(1, 0);
  output += vertSeparator;
  output += board->getMark(1, 1);
  output += vertSeparator;
  output += board->getMark(1, 2);
  output += horizSeparator;
  output += emptySpacer;
  output += board->getMark(2, 0);
  output += vertSeparator;
  output += board->getMark(2, 1);
  output += vertSeparator;
  output += board->getMark(2, 2);
  output += "\n";

  return output;
}
