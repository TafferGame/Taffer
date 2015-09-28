#pragma once

#define MAX_VISIBLE_NODES 2
#define MAX_NODES 100
//Map class.
//Contains all nodes on the map and currently visible nodes.
class MapClass {
public:
	void DrawVisibleNodes(int plX, int plY);
	//Testing function
	void InitializeEmptyMap();
	void Place(char object, int x, int y);
private:
	char nodes[MAX_NODES][MAX_NODES];
	//Testing variable
	char ** testNodes;
};