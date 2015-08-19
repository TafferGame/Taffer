#include "TAF.h"

char map[MAP_SIZE][MAP_SIZE];

struct Player plr;
struct Town * main_town;
void InitMapToEmpty(void);

int main() {
	setlocale(LC_CTYPE, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	struct Town * scoped_town = malloc(sizeof(struct Town));

	main_town = malloc(sizeof(struct Town));
	CreateTownMenu(main_town);

	InitMapToEmpty();

	plr.current_x = plr.current_y = plr.new_x = plr.new_y = 0;

	FILE * pFile = NULL;

	main_town->population = 1300;
	main_town->x = 9;
	main_town->y = 9;
	strcpy(main_town->town_buildings[0].name, "Барраки");
	main_town->town_buildings[0].type = BARRACKS;

	SaveStructToFile(main_town);

	LoadStructFromFile(pFile, scoped_town);
	PlaceTown(scoped_town);

	ShowMap();

	while (1) {
		GetUserControl();
		ShowMap();
	}

}

void InitMapToEmpty() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			map[j][i] = ' ';
		}
	}

	map[0][0] = 'P';
}

void ShowMap() {
	system("cls");

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			printf("%c", map[j][i]);
		}
		printf("\n");
	}
}