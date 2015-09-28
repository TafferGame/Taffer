#include "sandbox.h"
#include "map.h"

void MapClass::DrawVisibleNodes(int plX, int plY)
{
	for (int i = plX - MAX_VISIBLE_NODES; i <= MAX_VISIBLE_NODES; i++) {
		if (i >= 0) {
			for (int j = plY - MAX_VISIBLE_NODES; j <= MAX_VISIBLE_NODES; j++) {
				if (j >= 0)
				{
					printf("%c", nodes[i][j]);
				}
			}
			printf("\n");
		}
	}
}

void MapClass::InitializeEmptyMap()
{
	for (int i = 0; i < MAX_NODES; i++) {
		for (int j = 0; j < MAX_NODES; j++) {
			nodes[i][j] = 'o';
		}
	}
}

void MapClass::Place(char object, int x, int y) {
	nodes[x][y] = object;
}

/*void Zaglushka() {
	for (int i = 0; i < MAX_VISIBLE_NODES; i++) {
		for (int j = 0; j < MAX_VISIBLE_NODES; j++) {
			visibleNodes[i][j] = ' ';
		}
	}

	testNodes = (char**)malloc(MAX_VISIBLE_NODES * sizeof(char*));

	for (int i = 0; i < MAX_VISIBLE_NODES; i++) {
		*(testNodes + i) = (char*)malloc(MAX_VISIBLE_NODES * sizeof(char));
	}

	GetVisibleNodes(testNodes);

	for (int a = 0; a < MAX_VISIBLE_NODES; a++) {
		for (int b = 0; b < MAX_VISIBLE_NODES; b++) {
			printf("%c", testNodes[a][b]);
		}
		printf("\n");
	}
}*/