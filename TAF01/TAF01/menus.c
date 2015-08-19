#include "TAF.h"

void ShowTownInfo(struct Town * p_town) {
	system("cls");

	char * menu_title = "���� ������";
	int usr_cntrl;

	system("cls");
	printf("     ----------------------------     \n");
	printf("     |     %12s         |\n", menu_title);
	printf("     ----------------------------     \n");
	printf("     |     %12s         |\n", p_town->name);
	printf("     |  ���������: %4i         |    \n", p_town->population);
	printf("     |     %12s         |\n", p_town->town_buildings[0].name);
	printf("     ----------------------------     \n");

	usr_cntrl = _getch();
	usr_cntrl = _getch();

	if (usr_cntrl == 27) { return; }
}

void CreateTownMenu(struct Town * town_to_create) {
	setlocale(LC_CTYPE, "rus");
	printf("������� �������� ������... ");
	fgets(town_to_create->name, 12, stdin);
}