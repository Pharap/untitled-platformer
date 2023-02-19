#pragma once
#include <stdint.h>

enum class TileType : uint8_t
{
    Sky,
    Ground
};

constexpr uint8_t tileWidth = 8;
constexpr uint8_t tileHeight = 8;

inline constexpr uint8_t getTileIndex(TileType tileType)
{
    return static_cast<uint8_t>(tileType);
}