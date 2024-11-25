#pragma once
#include "player.hpp"

class basePlayer : public Player
{
    private:
    char mark{};
    
    public:
    basePlayer(Board *board, char mark);
    int getInput() override;
    void test() override;
    char getMark() override;
};