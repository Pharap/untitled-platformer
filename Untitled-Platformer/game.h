#pragma once
#include <stdint.h>

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
        void drawGame();

        void setup();
        void loop();
};