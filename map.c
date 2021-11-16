#include "map.h"

Map* creationMap() {
	Map* map = calloc(2, sizeof(Map));

	unsigned int i, j;
	for (i = 0; i < MAP_SIZE; i++) {
		for (j = 0; j < MAP_SIZE; j++) {
			map->map[i][j]= 1;
		}
	}

	return map;
}
