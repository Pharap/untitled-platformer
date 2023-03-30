#include "mapData.h"

namespace MapData
{
    const TileType (*mapData)[mapWidth] = map0Data;

    TileType getTile(int16_t x, int16_t y)
	{

		if((x >= fullMapWidth) || (y >= fullMapHeight))
		{
			return TileType::Sky;
		}

		else
		{
			const TileType * tilePointer = &mapData[y][x];

			return readTileTypeFromProgmem(tilePointer);
		}
	}
}
