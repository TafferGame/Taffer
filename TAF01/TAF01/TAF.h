#pragma once

#define _CRT_SECURE_NO_WARNINGS

#define MAP_SIZE 10

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <string.h>
#include <Windows.h>

enum BuildingTypes {
	BARRACKS = 1,
	ARMORY = 2,
	FARM = 3
};

struct Player {
	int current_x, current_y;
	int new_x, new_y;
};
struct Buildings {
	int type;
	char name[20];
};

struct Town {
	int x, y, population;
	char name[20];
	struct Buildings town_buildings[2];
};

//Menu functions
void ShowTownInfo(struct Town * p_town);
void CreateTownMenu(struct Town * town_to_create);

//File IO functuions
void SaveStructToFile(struct Town * inTown);
void LoadStructFromFile(FILE * file_to_load, struct Town * town_to_load);

//Control functions
void GetUserControl();
void MoveDown();
void MoveUp();
void MoveLeft();
void MoveRight();

void ShowMap();

//Map object placing functions
void PlaceTown(struct Town * in_town);