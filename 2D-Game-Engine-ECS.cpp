#include "CGame.h"

int main()
{
    CGame game;
    game.initialize("config.txt", "Fonts/sansation.ttf");
    game.run();

    return 0;
}