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
	game.arduboy.println(y);
    game.arduboy.println(xVelocity);
    game.arduboy.println(yVelocity);

    yVelocity += Physics::gravity;
    xVelocity *= Physics::friction;

	auto newX = (this->x + this->xVelocity);
    auto newY = (this->y + this->yVelocity);

    const int16_t tileX = ((newX + halfTileWidth) / tileWidth);
    const int16_t tileY = ((newY + halfTileHeight) / tileHeight);

    const int16_t rightX = (newX + this->size);

    const int16_t rightTileX = (rightX / tileWidth);

    const TileType rightTile = MapData::getTile(rightTileX, tileY);

    if(isSolid(rightTile))
    {
        newX = ((rightTileX * tileWidth) - this->size);
		xVelocity = 0;
    }
    
    const int16_t leftX = (newX);
    
    const int16_t leftTileX = (leftX / tileWidth);

    const TileType leftTile = MapData::getTile(leftTileX, tileY);

    if(isSolid(leftTile))
    {
        newX = ((leftTileX + 1) * tileWidth);
		xVelocity = 0;
    }

    const int16_t bottomY = (newY + this->size);

    const int16_t bottomTileY = (bottomY / tileHeight);

    const TileType bottomTile = MapData::getTile(tileX, bottomTileY);

    if(isSolid(bottomTile))
    {	
		newY = ((bottomTileY * tileHeight) - this->size);
		yVelocity = 0;

		grounded = true;
    }

	else
	{
		if (game.arduboy.everyXFrames(10))
			grounded = false;
	}

	game.arduboy.println(static_cast<uint8_t>(bottomTile));

    const int16_t topY = (newY - 1);

    const int16_t topTileY = (topY / tileHeight);

    const TileType topTile = MapData::getTile(tileX, topTileY);

    if(isSolid(topTile))
    {
        newY = ((topTileY + 1) * tileHeight);
		yVelocity = 0;
    }

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
        xVelocity += speed;

        isPlayerLeft = false;
    }

    if (game.arduboy.pressed(LEFT_BUTTON))
    {
        xVelocity -= speed;
    
        isPlayerLeft = true;
    }

    if (game.arduboy.pressed(UP_BUTTON))
    {    
		if (grounded)
		{
			yVelocity = 0;
			yVelocity -= thrust;
		}
    }
}

void Player::drawPlayer()
{
    Sprites::drawOverwrite((x - camera.x), (y  - camera.y), playerSprite, isPlayerLeft);
}
