#line 1 "/Users/om/Downloads/ARDUBOY/Untitled-Platformer/player.cpp"
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

    float newX = ((x + xVelocity) + halfTileWidth);
    float newY = ((y + yVelocity) + halfTileHeight);

    const int16_t tileX = (newX / tileWidth);
    const int16_t tileY = (newY / tileHeight);

    const int16_t rightX = (newX + halfTileWidth);

    const int16_t rightTileX = (rightX / tileWidth);

    const TileType rightTile = MapData::getTile(rightTileX, tileY);

    if(isSolid(rightTile))
	{
        newX = ((rightTileX * tileWidth) - halfTileWidth);

		xVelocity = 0;
	}

    const int16_t leftX = ((newX - halfTileWidth) - 1);
		
	const int16_t leftTileX = (leftX / tileWidth);

	const TileType leftTile = MapData::getTile(leftTileX, tileY);

	if(isSolid(leftTile))
	{
        newX = (((leftTileX + 1) * tileWidth) + halfTileWidth);

		xVelocity = 0;
	}

	game.arduboy.println(static_cast<uint8_t>(leftTile));

	const int16_t bottomY = (newY + halfTileHeight);

	const int16_t bottomTileY = (bottomY / tileHeight);

	const TileType bottomTile = MapData::getTile(tileX, bottomTileY);

	if(isSolid(bottomTile))
	{
    	newY = ((bottomTileY * tileHeight) - halfTileHeight);

		yVelocity = 0;
	}

	const int16_t topY = ((newY - halfTileHeight) - 1);

	const int16_t topTileY = (topY / tileHeight);

	const TileType topTile = MapData::getTile(tileX, topTileY);

	if(isSolid(topTile))
	{
        newY = (((topTileY + 1) * tileHeight) + halfTileWidth);

		yVelocity = 0;
	}

    x = (((newX > halfTileWidth) ? newX : halfTileWidth) - halfTileWidth);
    y = (((newY > halfTileHeight) ? newY : halfTileHeight) - halfTileHeight);
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
        xVelocity += speed;

        isPlayerLeft = false;
    }

    if (game.arduboy.pressed(LEFT_BUTTON))
    {
        xVelocity -= speed;
    
        isPlayerLeft = true;
    }

    if (game.arduboy.justPressed(UP_BUTTON))
    {
        yVelocity = 0;
        yVelocity -= thrust;
    }
}

void Player::drawPlayer()
{
    Sprites::drawOverwrite((x - camera.x), (y  - camera.y), playerSprite, isPlayerLeft);
}
