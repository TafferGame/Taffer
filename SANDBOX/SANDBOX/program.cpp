#include "sandbox.h"
#include "map.h"


int main() {
	BaseGame * pBaseGame = new BaseGame;
	pBaseGame->InitializeMap();
	pBaseGame->CreatePlayer();
	pBaseGame->PlacePlayer();
	pBaseGame->DrawMap();
	system("pause");
}
