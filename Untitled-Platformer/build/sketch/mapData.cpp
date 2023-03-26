#line 1 "/Users/om/Downloads/ARDUBOY/Untitled-Platformer/mapData.cpp"
#include "mapData.h"

namespace MapData
{
    const TileType (*currentMapData)[mapWidth] = map0Data;

    size_t getIndex(int16_t x, int16_t y)
	  {
		    return ((y * mapWidth) + x);
	  }

    TileType getTile(int16_t x, int16_t y)
	  {
		    const size_t index = getIndex(x, y);

		    const TileType * tilePointer = currentMapData[index];

		    return readTileTypeFromProgmem(tilePointer);
	  }
}
