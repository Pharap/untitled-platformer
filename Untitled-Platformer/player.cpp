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
    game.arduboy.println(camera.x);
    game.arduboy.println(x);
    game.arduboy.println(camera.isLeft);
    game.arduboy.println(camera.isRight);

    yVelocity += Physics::gravity;
    xVelocity *= Physics::friction;

    float newX = (x + xVelocity);
    float newY = (y + yVelocity);

    const float tileX = (newX / tileWidth);
    const float tileY = (newY / tileHeight);

    const float rightX = (newX + size);

    const float rightTileX = (rightX / tileWidth);

    const TileType rightTile = MapData::getTile(rightTileX, tileY);

    if(isSolid(rightTile))
		{
			  newX = ((rightTileX * tileWidth) - size);
		}

    const int16_t leftX = ((newX - size) - 1);
		
		// Find which tile the player's new left side is in
		const int16_t leftTileX = (leftX / tileWidth);

		// Find the tile the player is trying to move into
		const TileType leftTile = MapData::getTile(leftTileX, tileY);

		// If the tile is solid
		if(isSolid(leftTile))
		{
			// Adjust the player's position to prevent collision
			newX = (((leftTileX + 1) * tileWidth) + size);
		}

		// Find the x coordinate of the player's new bottom side
		const int16_t bottomY = (newY + size);

		// Find which tile the player's new bottom side is in
		const int16_t bottomTileY = (bottomY / tileHeight);

		// Find the tile the player is trying to move into
		const TileType bottomTile = MapData::getTile(tileX, bottomTileY);

		if(isSolid(bottomTile))
		{
			// Adjust the player's position to prevent collision
			newY = ((bottomTileY * tileHeight) - size);
		}

		// Find the x coordinate of the player's new top side
		const int16_t topY = ((newY - size) - 1);

		// Find which tile the player's new top side is in
		const int16_t topTileY = (topY / tileHeight);

		// Find the tile the player is trying to move into
		const TileType topTile = MapData::getTile(tileX, topTileY);

		// If the tile is solid
		if(isSolid(topTile))
		{
			// Adjust the player's position to prevent collision
			newY = (((topTileY + 1) * tileHeight) + size);
		}

    if (isPlayerLeft && newX <= 0 || !isPlayerLeft && newX >= 119)
        xVelocity = 0;

    x = ((newX > size) ? newX : size);
    y = ((newY > size) ? newY : size);
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
    Sprites::drawOverwrite(x - camera.x, y - camera.y, playerSprite, isPlayerLeft);
}
