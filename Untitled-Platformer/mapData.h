#pragma once
#include <stdint.h>
#include <avr/pgmspace.h>
#include "tileType.h"

namespace MapData
{
    constexpr uint8_t totalMaps = 2;
  
    constexpr uint8_t mapWidth = 48;
    constexpr uint8_t mapHeight = 8;

	constexpr uint8_t mapWidths[] = {48, 24};

    constexpr uint16_t fullMapWidth = (mapWidth * tileWidth);
    constexpr uint8_t fullMapHeight = (mapHeight * tileHeight);

    constexpr TileType map0Data[mapHeight][mapWidths[0]] PROGMEM =
    {
        {
            TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky
        },
        {
            TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Block, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky
        },
        {
            TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky
        },
        {
            TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky
        },
        {
            TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Block, TileType::Sky, TileType::Sky, TileType::LeftCap, TileType::SidewaysTube, TileType::SidewaysTube, TileType::SidewaysTube, TileType::RightCap, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Cap, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky
        },
        {
            TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Cap, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Tube, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky
        },
        {
            TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Cap, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Tube, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Tube, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky
        },
        {
            TileType::Ground,TileType::Ground,TileType::Ground,TileType::Ground,TileType::Ground,TileType::Ground,TileType::Ground,TileType::Ground,TileType::Ground,TileType::Ground,TileType::Ground,TileType::Ground,TileType::Ground,TileType::Ground,TileType::Ground,TileType::Ground, TileType::Ground, TileType::Ground, TileType::Ground, TileType::Ground, TileType::PixelBoth, TileType::Ground, TileType::Ground, TileType::Ground, TileType::Ground,TileType::PixelBoth,TileType::Ground,TileType::Ground,TileType::Ground,TileType::Ground,TileType::Ground,TileType::PixelBoth,TileType::Ground,TileType::Ground,TileType::Ground,TileType::Ground,TileType::Ground,TileType::Ground,TileType::Ground,TileType::Ground, TileType::Ground, TileType::Ground, TileType::Ground, TileType::Ground, TileType::Ground, TileType::Ground, TileType::Ground, TileType::Ground
        },
    };

    constexpr TileType map1Data[mapHeight][mapWidths[1]] PROGMEM =
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
            TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Tube, TileType::Sky, TileType::Sky, TileType::GroundLeft, TileType::Ground, TileType::GroundRight, TileType::Sky, TileType::Sky, TileType::LeftWallRightPixel, TileType::GroundRight, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky
        },
        {
            TileType::Ground,TileType::Ground,TileType::GroundRight,TileType::Sky,TileType::Sky,TileType::GroundLeft,TileType::PixelBoth,TileType::Ground,TileType::Ground,TileType::PixelLeft,TileType::Sky,TileType::PixelRight,TileType::Ground,TileType::Ground,TileType::PixelLeft,TileType::PixelRight, TileType::Ground, TileType::GroundRight, TileType::Sky, TileType::Sky, TileType::GroundLeft, TileType::Ground, TileType::Ground, TileType::Ground
        },	
    };

	extern const TileType *data[mapHeight][mapWidths[0]];

    extern TileType getTile(int16_t x, int16_t y);
}
