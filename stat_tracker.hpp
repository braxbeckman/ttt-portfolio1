#pragma once

class StatTracker
{
    private:
    int xWins{0};
    int oWins{0};
    int ties{0};

    public:
    int getXWins();
    int getOWins();
    int getTies();

    void logXWin();
    void logOWin();
    void logTie();

    void writeStats();
};