#include "player.h"
#include "game.h"
#include "sprites.h"
#include "camera.h"

Player player;
Camera camera;

void Player::updatePlayer()
{
    playerInput();

    game.arduboy.setCursor(0, 0);
    game.arduboy.println(camera.x);
    game.arduboy.println(x);
    game.arduboy.println(camera.isLeft);
    game.arduboy.println(camera.isRight);

    yVelocity += Physics::gravity;
    xVelocity *= Physics::friction;

    x += xVelocity;
    y += yVelocity;

    if (player.x == 58 && !camera.isLeft && !camera.isRight)
        player.x = 58;
}

void Camera::updateCamera()
{
    if (x <= 0)
        isLeft = true;

    if (x >= 64)
        isRight = true;

    if (isLeft)
    {
        if (player.x >= 58)
            isLeft = false;
    }

    if (isRight)
    {
        if (player.x <= 58)
            isRight = false;
    }

    if (!isLeft && !isRight)
    {
      x += player.xVelocity;
      y += player.yVelocity;
    }
}

void Player::playerInput()
{   
    if (game.arduboy.pressed(RIGHT_BUTTON))
    {
        xVelocity += speed;

        isPlayerLeft = false;
    }

    if (game.arduboy.pressed(LEFT_BUTTON))
    {
        xVelocity -= speed;

        isPlayerLeft = true;
    }
}

void Player::drawPlayer()
{
    Sprites::drawOverwrite(x, y, playerSprite, isPlayerLeft);
}
