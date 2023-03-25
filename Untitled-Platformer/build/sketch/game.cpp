#line 1 "/Users/om/Downloads/ARDUBOY/Untitled-Platformer/game.cpp"
#include "game.h"
#include "tileType.h"
#include "mapData.h"
#include "sprites.h"
#include "player.h"
#include "camera.h"

Arduboy2 arduboy;
Game game;
Game::GameState gameState;

void Game::setup()
{
    arduboy.begin();
}

void Game::loop()
{
    if(!arduboy.nextFrame())
        return;

    arduboy.pollButtons();

    arduboy.clear();
    update();
    arduboy.display();
}

void Game::update()
{
    switch(gameState)
    {
        case GameState::Title:
            if (arduboy.justPressed(A_BUTTON)) {gameState = GameState::Game;}
                break;

        case GameState::Game:
            updateGame();
            drawMap();
            player.updatePlayer();
            camera.updateCamera();
            player.drawPlayer();

            if (arduboy.justPressed(A_BUTTON)) {MapData::currentMapData = MapData::map1Data;}
                break;

        case GameState::Gameover:
                break;
    }
}

void Game::updateGame()
{

}

void Game::drawMap()
{
    for(uint8_t tileY = 0; tileY < MapData::mapHeight; ++tileY)
    {
        int16_t drawY = ((tileY * tileHeight) - camera.y);

        if ((drawY < -tileHeight) || (drawY > HEIGHT))

            continue;

        for(uint8_t tileX = 0; tileX < MapData::mapWidth; ++tileX)
        {
            int16_t drawX = ((tileX * tileWidth) - camera.x);

            if((drawX < -tileWidth) || (drawX > WIDTH))

                continue;

             TileType tileType = readTileTypeFromProgmem(&MapData::currentMapData[tileY][tileX]);

            uint8_t tileIndex = getTileIndex(tileType);

            Sprites::drawSelfMasked(drawX, drawY, mapTiles, tileIndex);
        }
    }
}
