#include "mapData.h"

namespace MapData
{
    const TileType (*currentMapData)[MapData::mapWidth] = map0Data;

    const TileType *data = &currentMapData[0][0];

    size_t getIndex(float x, float y)
	  {
		    return ((y * mapWidth) + x);
	  }

    TileType getTile(float x, float y)
	  {
		    if((x > mapWidth) || (y > mapHeight))
		    {
			      return TileType::Sky;
		    }

		    const size_t index = getIndex(x, y);

		    const TileType * tilePointer = &data[index];

		    return readTileTypeFromProgmem(tilePointer);
	  }
}
