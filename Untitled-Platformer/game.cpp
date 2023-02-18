#include "game.h"
#include <Arduboy2.h>

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
                break;

        case GameState::Game:
            updateGame();
            drawGame();
                break;

        case GameState::Gameover:
                break;
    }
}

void Game::updateGame()
{

}

void Game::drawGame()
{
    
}
