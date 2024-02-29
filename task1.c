#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task1.h"

double salariu(const livratorBolt* livrator) {
	//scuter - 2l/100km

	//masina - 10l/100km

	//bicicleta - 0l

	float castigPeOra;

	int km;

	if (livrator->program == deNoapte) {
		castigPeOra = 19.5;

		km = 16;
	}

	else {
		castigPeOra = 25;

		km = 20;
	}

	float consum = 0;

	if (!strcmp(livrator->automobil, "scuter")) {
		consum = ((livrator->oreDeLucru * km) / 100) * 2;
	}

	else if (!strcmp(livrator->automobil, "masina")) {
		consum = ((livrator->oreDeLucru * km) / 100) * 10;
	}

	printf("%f\n", consum);

	return castigPeOra * livrator->oreDeLucru * 30 - consum * 7.5;
}

void modificare(livratorBolt* livrator, float ore) {
	livrator->oreDeLucru = ore;
}

livratorBolt citire() {
	livratorBolt livrator;

	printf("\nCodul livratorului:");

	scanf("%ld", &livrator.cod);

	char buffer[100];

	printf("Metoda de deplasare:");

	scanf("%s", buffer);

	livrator.automobil = malloc(strlen(buffer) + 1);

	strcpy(livrator.automobil, buffer);

	printf("Ore de lucru:");

	scanf("%f", &livrator.oreDeLucru);

	char interval[100];

	printf("Interval zi/noapte:");

	scanf("%s", interval);

	livrator.program = (strcmp(interval, "zi") == 0 || strcmp(interval, "Zi") == 0) ? deZi : deNoapte;

	return livrator;
}

void afisare(const livratorBolt* livrator) {
	printf("\nCod:%ld", livrator->cod);

	printf("\nDeplasare:%s", livrator->automobil);

	printf("\nOre:%.1f", livrator->oreDeLucru);

	printf("\nInterval:");

	if (livrator->program == deZi)

		printf("zi");

	else

		printf("noapte");
}

void stergeLivratorBolt(livratorBolt livrator)

{
	if (livrator.automobil != NULL)

	{
		free(livrator.automobil);
	}
}