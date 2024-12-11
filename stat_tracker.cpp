#include "stat_tracker.hpp"
#include <fstream>

int StatTracker::getXWins()
{
    return xWins;
}

int StatTracker::getOWins()
{
    return oWins;
}

int StatTracker::getTies()
{
    return ties;
}

void StatTracker::logXWin()
{
    xWins++;
}

void StatTracker::logOWin()
{
    oWins++;
}

void StatTracker::logTie()
{
    ties++;
}

void StatTracker::writeStats()
{
    std::ofstream output("game stats.txt");

    output << "You played " << xWins + oWins + ties << " games" << std::endl;
    output << "X won " << xWins << " times" << std::endl;
    output << "O won " << oWins << " times" << std::endl;
    output << "You tied " << ties << " times" << std::endl;

    output.close();
}