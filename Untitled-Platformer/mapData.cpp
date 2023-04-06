#include "mapData.h"

namespace MapData
{
    const TileType *data[mapHeight][mapWidths[0]];

	const uint8_t *currentMapWidth = &mapWidths[0];

    TileType getTile(int16_t x, int16_t y)
	{

		if ((y <= 0) || (x >= mapWidth) || (y >= mapHeight))
		{
			return TileType::Sky;
		}

		const TileType *tilePointer = data[y][x];

		return readTileTypeFromProgmem(tilePointer);
	}
}
