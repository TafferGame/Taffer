#include "TAF.h"

void SaveStructToFile(struct Town * inTown) {
	FILE * pFile;

	pFile = fopen("towns1.taf", "wb");

	fwrite(inTown, sizeof(struct Town), 1, pFile);

	fclose(pFile);
}

void LoadStructFromFile(FILE * file_to_load, struct Town * town_to_load) {
	file_to_load = fopen("towns1.taf", "rb");

	fread(town_to_load, sizeof(struct Town), 1, file_to_load);

	fclose(file_to_load);
}
