#include "CGame.h"

int main()
{
    int iReturnValue = 0;

    CGame game;

    try
    {
        game.initialize("config.txt", "Fonts/sansation.ttf");
        game.run();
    }
    catch (std::runtime_error & er)
    {
        std::cout << "Game Exception. " << er.what() << std::endl;
        iReturnValue = 1;
    }

    return iReturnValue;
}