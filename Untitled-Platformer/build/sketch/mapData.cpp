#line 1 "/Users/om/Downloads/ARDUBOY/Untitled-Platformer/mapData.cpp"
#include "mapData.h"

namespace MapData
{
    TileType const (*currentMapData)[MapData::mapWidth] = map0Data;

    TileType const *data = &currentMapData[0][0];

    size_t getIndex(float x, float y)
	  {
		    return ((y * mapWidth) + x);
	  }

    TileType getTile(float x, float y)
	  {
		    size_t const index = getIndex(x, y);

		    TileType const * tilePointer = &data[index];

		    return readTileTypeFromProgmem(tilePointer);
	  }
}
