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
            player.drawPlayer();
            camera.updateCamera();

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
    for(uint8_t tileY = 0; tileY < MapData::mapHeight[MapData::currentMapSize]; ++tileY)
    {
        int16_t drawY = ((tileY * tileHeight) - camera.y);

        if ((drawY < -tileHeight) || (drawY > HEIGHT))

            continue;

        for(uint8_t tileX = 0; tileX < MapData::mapWidth[MapData::currentMapSize]; ++tileX)
        {
            int16_t drawX = ((tileX * tileWidth) - camera.x);

            if((drawX < -tileWidth) || (drawX > WIDTH))

                continue;

            TileType tileType = static_cast<TileType>(pgm_read_byte(&MapData::currentMapData[tileY][tileX]));

            uint8_t tileIndex = getTileIndex(tileType);

            Sprites::drawOverwrite(drawX, drawY, mapTiles, tileIndex);
        }
    }
}
