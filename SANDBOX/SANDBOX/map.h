#pragma once

#define MAX_VISIBLE_NODES 10
class Map {
public:
	void GetVisibleNodes(char**);
	void TestNodes();
private:
	char nodes[100][100];
	char visibleNodes[MAX_VISIBLE_NODES][MAX_VISIBLE_NODES];
	char ** testNodes;
};