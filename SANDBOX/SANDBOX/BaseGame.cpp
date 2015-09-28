#include "sandbox.h"
#include "map.h"

void BaseGame::InitializeMap() {
	gameMap = new MapClass;
	gameMap->InitializeEmptyMap();
}

void BaseGame::CreatePlayer() {
	player = new PlayerClass;
	printf("Enter your player name ");
	std::cin.getline(player->playerName, sizeof(char[100]));
	player->currentX = 0; player->currentY = 0;
	system("cls");
}

void BaseGame::PlacePlayer()
{
	gameMap->Place('p', player->currentX, player->currentY);
}

void BaseGame::DrawMap()
{
	gameMap->DrawVisibleNodes(player->currentX, player->currentY);
}

BaseGame::BaseGame()
{
	gameJobs = 0;
	gameMap = 0;
	unitList = 0;
	player = 0;
}

BaseGame::~BaseGame()
{
	gameJobs = 0;
	gameMap = 0;
	unitList = 0;
	player = 0;
}
