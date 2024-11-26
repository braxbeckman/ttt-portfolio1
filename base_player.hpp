#pragma once
#include "player.hpp"
#include <string>

class basePlayer : public Player
{
    private:
    char mark{};
    std::string archetype{"base"};

    public:
    basePlayer(Board *board, char mark);
    int getInput() override;
    void test() override;
    char getMark() override;
    std::string getArchetype() override;
};