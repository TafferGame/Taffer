#include "TAF.h"

extern struct Player plr;
extern char map[MAP_SIZE][MAP_SIZE];
extern struct Town * main_town;

void GetUserControl() {
	int usr_cntrl;
	usr_cntrl = _getch();
	usr_cntrl = _getch();
	//printf("%i", usr_cntrl);
	//system("pause");

	switch (usr_cntrl)
	{
	case 80:
		MoveDown();
		break;
	case 72:
		MoveUp();
		break;
	case 75:
		MoveLeft();
		break;
	case 77:
		MoveRight();
		break;
	default:
		break;
	}
	
}

void MoveDown() {
	plr.new_y = plr.current_y + 1;

	if (map[plr.current_x][plr.new_y] == ' ' && plr.new_y != -1 && plr.new_y < 10)
	{
		map[plr.current_x][plr.current_y] = ' ';
		map[plr.current_x][plr.new_y] = 'P';
		plr.current_y = plr.new_y;
	}
	else if (map[plr.current_x][plr.new_y] == 'T') {
		if (main_town->x == plr.current_x && main_town->y == plr.new_y) {
			ShowTownInfo(main_town);
		}
	}
	else return;
}

void MoveUp() {
	plr.new_y = plr.current_y - 1;

	if (map[plr.current_x][plr.new_y] == ' ' && plr.new_y != -1 && plr.new_y < 10)
	{
		map[plr.current_x][plr.current_y] = ' ';
		map[plr.current_x][plr.new_y] = 'P';
		plr.current_y = plr.new_y;
	}
	else if (map[plr.current_x][plr.new_y] == 'T') {
		if (main_town->x == plr.current_x && main_town->y == plr.new_y) {
			ShowTownInfo(main_town);
		}
	}
	else return;
}

void MoveLeft() {
	plr.new_x = plr.current_x - 1;
	
	if (map[plr.new_x][plr.current_y] == ' ' && plr.new_x != -1 && plr.new_x < 10)
	{
		map[plr.current_x][plr.current_y] = ' ';
		map[plr.new_x][plr.current_y] = 'P';
		plr.current_x = plr.new_x;
	}
	else if (map[plr.new_x][plr.current_y] == 'T') {
		if (main_town->x == plr.new_x && main_town->y == plr.current_y) {
			ShowTownInfo(main_town);
		}
	}
}

void MoveRight() {
	plr.new_x = plr.current_x + 1;

	if (map[plr.new_x][plr.current_y] == ' ' && plr.new_x != -1 && plr.new_x < 10)
	{
		map[plr.current_x][plr.current_y] = ' ';
		map[plr.new_x][plr.current_y] = 'P';
		plr.current_x = plr.new_x;
	}
	else if (map[plr.new_x][plr.current_y] == 'T') {
		if (main_town->x == plr.new_x && main_town->y == plr.current_y) {
			ShowTownInfo(main_town);
		}
	}
}

void PlaceTown(struct Town * in_town) {
	map[in_town->x][in_town->y] = 'T';
}