#pragma once
#include <stdint.h>
#include <avr/pgmspace.h>
#include "tileType.h"

namespace MapData
{
    extern uint8_t totalMaps;
  
    constexpr uint8_t map0Width = 24;
    constexpr uint8_t map0Height = 8;

    constexpr uint8_t fullMap0Width = (map0Width * tileWidth);
    constexpr uint8_t fullMap0Height = (map0Height * tileHeight);

    extern uint8_t *currentMapWidth[];
    extern uint8_t *currentMapHeight[];

    extern uint8_t *currentFullMapWidth[];
    extern uint8_t *currentFullMapHeight[];

    constexpr TileType map0Data[map0Height][map0Width] PROGMEM =
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
}
