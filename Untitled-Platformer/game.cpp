#include "game.h"
#include "tileType.h"
#include "mapData.h"
#include "sprites.h"

Arduboy2 arduboy;
Game game;
Game::GameState gameState;
MapData mapData;

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
    for(uint8_t tileY = 0; tileY < MapData::map0Height; ++tileY)
    {
        int16_t drawY = ((tileY * tileHeight) - mapData.cameraY);

        if ((drawY < -tileHeight) || (drawY > HEIGHT))

            continue;

        for(uint8_t tileX = 0; tileX < MapData::map0Width; ++tileX)
        {
            int16_t drawX = ((tileX * tileWidth) - mapData.cameraX);

            if((drawX < -tileWidth) || (drawX > WIDTH))

                continue;

            TileType tileType = mapData.map0Data[tileY][tileX];

            uint8_t tileIndex = getTileIndex(tileType);

            Sprites::drawOverwrite(drawX, drawY, mapTiles, tileIndex);
        }
    }
}
