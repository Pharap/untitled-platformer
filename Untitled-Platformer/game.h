#pragma once
#include <stdint.h>
#include <Arduboy2.h>

class Game
{
    private:

    public:

        enum class GameState : uint8_t
        {
            Title,
            Game,
            Gameover
        };

        void update();

        void updateGame();
        void drawMap();

        void setup();
        void loop();

        Arduboy2 arduboy;
};