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
		
		const int16_t leftTileX = (leftX / tileWidth);

		const TileType leftTile = MapData::getTile(leftTileX, tileY);

		if(isSolid(leftTile))
		{
			  newX = (((leftTileX + 1) * tileWidth) + size);
		}

		const int16_t bottomY = (newY + size);

		const int16_t bottomTileY = (bottomY / tileHeight);

		const TileType bottomTile = MapData::getTile(tileX, bottomTileY);

		if(isSolid(bottomTile))
		{
			  newY = ((bottomTileY * tileHeight) - size);
		}

		const int16_t topY = ((newY - size) - 1);

		const int16_t topTileY = (topY / tileHeight);

		const TileType topTile = MapData::getTile(tileX, topTileY);

		if(isSolid(topTile))
		{
			  newY = (((topTileY + 1) * tileHeight) + size);
		}

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
        x = (player.x - (Arduboy2::width() / 2));
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
