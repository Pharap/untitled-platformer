#pragma once
#include <stdint.h>
#include <avr/pgmspace.h>
#include "tileType.h"

namespace MapData
{
    constexpr uint8_t totalMaps = 2;
    extern uint8_t currentMapSize;
  
    constexpr uint8_t mapWidth[totalMaps] = {24, 24};
    constexpr uint8_t mapHeight[totalMaps] = {8, 8};

    constexpr uint8_t fullMapWidth[totalMaps]; //= (mapWidth * tileWidth);
    constexpr uint8_t fullMapHeight[totalMaps]; //= (mapHeight * tileHeight);

    constexpr TileType map0Data[mapHeight[0]][mapWidth[0]] PROGMEM =
    {
        {
            TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky
        },
        {
            TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky
        },
        {
            TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky
        },
        {
            TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky
        },
        {
            TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky
        },
        {
            TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Cap, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Cap, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky
        },
        {
            TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Tube, TileType::Sky, TileType::Sky, TileType::GroundLeft, TileType::Ground, TileType::GroundRight, TileType::Sky, TileType::Sky, TileType::LeftWallRightPixel, TileType::Ground, TileType::LeftWall, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky
        },
        {
            TileType::Ground,TileType::Ground,TileType::Ground,TileType::Ground,TileType::Ground,TileType::Ground,TileType::PixelBoth,TileType::Ground,TileType::Ground,TileType::PixelLeft,TileType::Sky,TileType::PixelRight,TileType::Ground,TileType::Ground,TileType::PixelLeft,TileType::Sky, TileType::Ground, TileType::Ground, TileType::Ground, TileType::Ground, TileType::Ground, TileType::Ground, TileType::Ground, TileType::Ground
        }
    };

    constexpr TileType map1Data[mapHeight[1]][mapWidth[1]] PROGMEM =
    {
        {
            TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky
        },
        {
            TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky
        },
        {
            TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky
        },
        {
            TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky
        },
        {
            TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky
        },
        {
            TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Cap, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Cap, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky
        },
        {
            TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Tube, TileType::Sky, TileType::Sky, TileType::GroundLeft, TileType::Ground, TileType::GroundRight, TileType::Sky, TileType::Sky, TileType::LeftWallRightPixel, TileType::Ground, TileType::LeftWall, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky
        },
        {
            TileType::Ground,TileType::Ground,TileType::GroundRight,TileType::Sky,TileType::Sky,TileType::GroundLeft,TileType::PixelBoth,TileType::Ground,TileType::Ground,TileType::PixelLeft,TileType::Sky,TileType::PixelRight,TileType::Ground,TileType::Ground,TileType::PixelLeft,TileType::Sky, TileType::Ground, TileType::Ground, TileType::Ground, TileType::Ground, TileType::Ground, TileType::Ground, TileType::Ground, TileType::Ground
        }
    };

    extern const TileType (*currentMapData)[24];
}
