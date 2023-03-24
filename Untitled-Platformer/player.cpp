#include "player.h"
#include "game.h"
#include "sprites.h"
#include "camera.h"
#include "tileType.h"
#include "mapData.h"

Player player;
Camera camera;

void Player::updatePlayer()
{
    playerInput();

    game.arduboy.setCursor(0, 0);
    game.arduboy.println(x);
    game.arduboy.println(xVelocity);
    game.arduboy.println(yVelocity);

    yVelocity += Physics::gravity;
    xVelocity *= Physics::friction;

    this->updatePosition();
}

void Player::updatePosition()
{
    constexpr uint8_t halfWidth = (width / 2);
    constexpr uint8_t halfHeight = (height / 2);

    // Figure out the point that the player should be moving to
    auto newX = (this->x + this->xVelocity);
    auto newY = (this->y + this->yVelocity);

    // Figure out the tile coordinate that the player should be moving to
    const int16_t tileX = ((newX + halfWidth) / tileWidth);
    const int16_t tileY = ((newY + halfHeight) / tileHeight);

    // Find the x coordinate of the player's new right side
    const int16_t rightX = (newX + this->width);

    // Find which tile the player's new right side is in
    const int16_t rightTileX = (rightX / tileWidth);

    // Find the tile the player is trying to move into
    const TileType rightTile = MapData::getTile(rightTileX, tileY);

    // If the tile is solid
    if(isSolid(rightTile))
    {
        // Adjust the player's position to prevent collision
        newX = ((rightTileX * tileWidth) - this->width);
    }
    
    // Find the x coordinate of the player's new left side
    const int16_t leftX = (newX - 1);
    
    // Find which tile the player's new left side is in
    const int16_t leftTileX = (leftX / tileWidth);

    // Find the tile the player is trying to move into
    const TileType leftTile = MapData::getTile(leftTileX, tileY);

    // If the tile is solid
    if(isSolid(leftTile))
    {
        // Adjust the player's position to prevent collision
        newX = ((leftTileX + 1) * tileWidth);
    }

    // Find the x coordinate of the player's new bottom side
    const int16_t bottomY = (newY + this->height);

    // Find which tile the player's new bottom side is in
    const int16_t bottomTileY = (bottomY / tileHeight);

    // Find the tile the player is trying to move into
    const TileType bottomTile = MapData::getTile(tileX, bottomTileY);

    if(isSolid(bottomTile))
    {
        // Adjust the player's position to prevent collision
        newY = ((bottomTileY * tileHeight) - this->height);
    }

    // Find the x coordinate of the player's new top side
    const int16_t topY = (newY - 1);

    // Find which tile the player's new top side is in
    const int16_t topTileY = (topY / tileHeight);

    // Find the tile the player is trying to move into
    const TileType topTile = MapData::getTile(tileX, topTileY);

    // If the tile is solid
    if(isSolid(topTile))
    {
        // Adjust the player's position to prevent collision
        newY = ((topTileY + 1) * tileHeight);
    }

    // Assign the player's new position
    // Whilst preventing the position from going out of bounds
    this->x = ((newX > 0) ? newX : 0);
    this->y = ((newY > 0) ? newY : 0);
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
        if (player.x <= 128)
            isRight = false;
    }

    if (!isLeft && !isRight)
    {
        x = (player.x - (Arduboy2::width() / 2));
    }
}

void Player::playerInput()
{   
    if (game.arduboy.pressed(RIGHT_BUTTON))
    {
        if (true) 
            xVelocity += speed;

        isPlayerLeft = false;
    }

    if (game.arduboy.pressed(LEFT_BUTTON))
    {
        if (true)
            xVelocity -= speed;
    
        isPlayerLeft = true;
    }

    if (game.arduboy.justPressed(UP_BUTTON))
    {
        yVelocity = 0;
        yVelocity -= 1.2;
    }
}

void Player::drawPlayer()
{
    Sprites::drawOverwrite(x - camera.x, y - camera.y, playerSprite, isPlayerLeft);
}
