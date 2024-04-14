#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

#include<stdlib.h>

#include<string.h>

typedef struct {
	long cod;

	char* automobil;

	float oreDeLucru;

	enum {
		deZi,

		deNoapte
	} program;
} livratorBolt;

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

void stergeLivratorBolt(livratorBolt livrator)

{
	if (livrator.automobil != NULL)

	{
		free(livrator.automobil);
	}
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

livratorBolt* copiereObiecte(livratorBolt* vectObiecte, int lungime, float oreMinime) {
	livratorBolt* newVector = malloc(lungime * sizeof(livratorBolt));

	if (newVector == NULL) {
		printf("Eroare la alocarea memoriei!");

		exit(1);
	}

	int nrObiecteCopiate = 0;

	for (int i = 0; i < lungime; i++) {
		if (vectObiecte[i].oreDeLucru >= oreMinime) {
			newVector[nrObiecteCopiate] = vectObiecte[i];

			nrObiecteCopiate++;
		}
	}

	if (nrObiecteCopiate > 0)

	{
		newVector = realloc(newVector, nrObiecteCopiate * sizeof(livratorBolt));

		if (newVector == NULL) {
			printf("Eroare la realocarea memoriei!");

			exit(1);
		}
	}

	else

	{
		printf("Nu exista livratori care sa corespunda cerintei.");

		exit(1);
	}

	return newVector;
}

livratorBolt* concatenareVectori(livratorBolt* vector1, int lungime1, livratorBolt* vector2, int lungime2) {
	livratorBolt* noulVector = malloc((lungime1 + lungime2) * sizeof(livratorBolt));

	if (noulVector == NULL) {
		printf("Eroare la alocarea memoriei!");

		exit(1);
	}

	for (int i = 0; i < lungime1; ++i) {
		noulVector[i] = vector1[i];
	}

	for (int i = 0; i < lungime2; ++i) {
		noulVector[lungime1 + i] = vector2[i];
	}

	return noulVector;
}

void afisareVector(livratorBolt* vector, int lungime)

{
	for (int i = 0; i < lungime; ++i) {
		printf("\nLivratorul %d:", i + 1);

		afisare(&vector[i]);
	}
}

int main() {
	int n = 1;

	livratorBolt* vector = malloc(sizeof(livratorBolt) * n);

	for (int i = 0; i < n; i++)

	{
		printf("\nIntroduceti datele pentru livratorul %d:", i + 1);

		vector[i] = citire();
	}

	livratorBolt* vectorNou = copiereObiecte(vector, n, 6);

	int m = 1;

	livratorBolt* vector1 = malloc(sizeof(livratorBolt) * m);

	for (int i = 0; i < m; i++)

	{
		printf("\nIntroduceti datele pentru livratorul %d:", i + 1);

		vector1[i] = citire();
	}

	livratorBolt* vectorConcatenat = concatenareVectori(vector, n, vector1, m);

	afisareVector(vectorConcatenat, n + m);

	free(vector);

	free(vectorNou);

	free(vectorConcatenat);

	return 0;
}