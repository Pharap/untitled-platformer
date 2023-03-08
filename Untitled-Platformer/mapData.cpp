#include "mapData.h"

namespace MapData
{
    const TileType (*currentMapData)[MapData::mapWidth] = map0Data;

    const TileType *data = nullptr;

    uint8_t width = 0;
    uint8_t height = 0;

    size_t getIndex(float x, float y)
	  {
		    return ((y * width) + x);
	  }

    TileType getTile(float x, float y)
	  {
		    if((x > width) || (y > height))
		    {
			      return TileType::Sky;
		    }

		    const size_t index = getIndex(x, y);

		    const TileType * tilePointer = &data[index];

		    return readTileTypeFromProgmem(tilePointer);
	  }
}
