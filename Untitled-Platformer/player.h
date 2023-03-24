#pragma once
#include <stdint.h>
#include <Arduboy2.h>

class Player
{
    private:

    struct Physics
    {
        static constexpr float gravity = 0.03;
        static constexpr float friction = 0.92;
    };

    static constexpr uint8_t width = 8;
    static constexpr uint8_t height = 8;

    static constexpr uint8_t size = 8;

    static constexpr float speed = 0.13;

    bool isPlayerLeft;

    bool canMoveRight;
    bool canMoveLeft;

    void playerInput();

    public:

    float x;
    float y;

    float xVelocity;
    float yVelocity;

    void updatePlayer();
    void drawPlayer();

private:
    void updatePosition();
};

extern Player player;
