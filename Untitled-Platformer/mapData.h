#pragma once
#include <stdint.h>
#include <avr/pgmspace.h>

class MapData
{
    private:

    public:

        static constexpr uint8_t map0Width = 16;
        static constexpr uint8_t map0Height = 8;

        static constexpr uint8_t fullMap0Width = (map0Width * tileWidth);
        static constexpr uint8_t fullMap0Height = (map0Height * tileHeight);

        const TileType map0Data[map0Height][map0Width] PROGMEM =
        {
            {
                TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky
            },
            {
                TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky
            },
            {
                TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky, TileType::Sky
            },
            {
                TileType::Ground,TileType::Ground,TileType::Ground,TileType::Ground,TileType::Ground,TileType::Sky,TileType::Sky,TileType::Sky,TileType::Ground,TileType::Ground,TileType::Ground,TileType::Ground,TileType::Ground,TileType::Ground,TileType::Ground,TileType::Ground
            }
        };

        int16_t cameraX = (fullMap0Width / 2);
        int16_t cameraY = (fullMap0Height / 2);

        static constexpr int16_t cameraXMinimum = 0;
        static constexpr int16_t cameraXMaximum = (fullMap0Width - 128);
        static constexpr int16_t cameraYMinimum = 0;
        static constexpr int16_t cameraYMaximum = (fullMap0Height - 64);
};
