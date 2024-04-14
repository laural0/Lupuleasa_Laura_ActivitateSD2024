#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct livratorBolt {
	long cod;
	char* automobil;
	float oreDeLucru;
	enum Program {
		deZi,
		deNoapte
	} program;
};

float salariu(const struct livratorBolt* livratorBolt) {
	float castigPeOra;
	int km;
	if (livratorBolt->program == deNoapte) {
		castigPeOra = 19.5;
		km = 16;
	}
	else {
		castigPeOra = 25;
		km = 20;
	}

	float consum = 0;
	if (strcmp(livratorBolt->automobil, "scuter") == 0) {
		consum = ((livratorBolt->oreDeLucru * km) / 100.0) * 2;
	}
	else if (strcmp(livratorBolt->automobil, "masina") == 0) {
		consum = ((livratorBolt->oreDeLucru * km) / 100.0) * 10;
	}

	printf("%.2f\n", consum);
	return castigPeOra * livratorBolt->oreDeLucru * 30 - consum * 7.5;
}

void citire(struct livratorBolt* livratorBolt) {
	printf("\nCodul livratorului: ");
	scanf("%ld", &livratorBolt->cod);

	char buffer[100];
	printf("Metoda de deplasare: ");
	scanf("%s", buffer);
	livratorBolt->automobil = (char*)malloc(strlen(buffer) + 1);
	strcpy(livratorBolt->automobil, buffer);

	printf("Ore de lucru: ");
	scanf("%f", &livratorBolt->oreDeLucru);

	printf("Interval zi/noapte: ");
	scanf("%s", buffer);
	livratorBolt->program = (strcmp(buffer, "zi") == 0) ? deZi : deNoapte;
}

void afisare(struct livratorBolt* livratorBolt) {
	printf("\nCod: %ld", livratorBolt->cod);
	printf("\nDeplasare: %s", livratorBolt->automobil);
	printf("\nOre: %.2f", livratorBolt->oreDeLucru);
	printf("\nInterval: %s", (livratorBolt->program == deZi) ? "zi" : "noapte");
}

int main() {
	struct livratorBolt livrator1;
	citire(&livrator1);

	afisare(&livrator1);
	printf("\nSalariu: %.2f", salariu(&livrator1));

	return 0;
}