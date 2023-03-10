#pragma once
#include <stdint.h>
#include <Arduboy2.h>

class Player
{
    private:

    struct Physics
    {
        static constexpr float gravity = 0.001;
        static constexpr float friction = 0.92;
    };

    static constexpr uint8_t size = 8;

    static constexpr float speed = 0.13;

    bool isPlayerLeft;

    void playerInput();

    public:

    float x;
    float y;

    float xVelocity;
    float yVelocity;

    void updatePlayer();
    void drawPlayer();
};

extern Player player;
