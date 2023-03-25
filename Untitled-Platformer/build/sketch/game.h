#line 1 "/Users/om/Downloads/ARDUBOY/Untitled-Platformer/game.h"
#pragma once
#include <stdint.h>
#include <Arduboy2.h>

class Game
{
    private:

        void update();

        void updateGame();
        void drawMap();

    public:

        enum class GameState : uint8_t
        {
            Title,
            Game,
            Gameover
        };

        void setup();
        void loop();

        Arduboy2 arduboy;
};

extern Game game;