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

    float newX = (x + xVelocity);
    float newY = (y + yVelocity);

    const float tileX = (newX / tileWidth);
    const float tileY = (newY / tileHeight);

    const int16_t rightX = (newX + size);

    const int16_t rightTileX = (rightX / tileWidth);

    const TileType rightTile = MapData::getTile(rightTileX, tileY);

    if(isSolid(rightTile))
		{
        newX = ((rightTileX * tileWidth) - size);

			  xVelocity = 0;

        canMoveRight = false;
		}
    
    else
    {
       canMoveRight = true;
    }

    const int16_t leftX = (newX);
		
		const int16_t leftTileX = (leftX / tileWidth);

		const TileType leftTile = MapData::getTile(leftTileX, tileY);

		if(isSolid(leftTile))
		{
        newX = (leftTileX * tileWidth);

			  xVelocity = 0;

        canMoveLeft = false;
		}

    else
    {
      canMoveLeft = true;
    }

		const int16_t bottomY = (newY + size);

		const int16_t bottomTileY = (bottomY / tileHeight);

		const TileType bottomTile = MapData::getTile(tileX, bottomTileY);

		if(isSolid(bottomTile))
		{
        newY = ((bottomTileY * tileHeight) - size);

			  yVelocity = 0;
		}

		const int16_t topY = (newY);

		const int16_t topTileY = (topY / tileHeight);

		const TileType topTile = MapData::getTile(tileX, topTileY);

		if(isSolid(topTile))
		{
        //newY = (topY + 1);

			  //yVelocity = 0;
		}

    x = newX;
    y = newY;
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
        yVelocity -= 1;
    }
}

void Player::drawPlayer()
{
    Sprites::drawOverwrite(x - camera.x, y - camera.y, playerSprite, isPlayerLeft);
}
