#define _CRT_SECURE_NO_WARNINGS

#include <iso646.h>
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct livratorBolt livrator_bolt;
struct livratorBolt {
	long cod;

	char* automobil;

	float oreDeLucru;

	enum {
		deZi,

		deNoapte
	} program;
};

void afisare(const livrator_bolt* livrator) {
	printf("Cod: %-4ld ", livrator->cod);
	printf("Deplasare: %-10s ", livrator->automobil);
	printf("Ore: %-4.1f ", livrator->oreDeLucru);
	printf("Interval: ");
	if (livrator->program == deZi)
		printf("%-4s", "zi");
	else
		printf("%-7s", "noapte");

	printf("\n");
}

livrator_bolt constructor(long cod, char* automobil, float ore,
	int program)
{
	livrator_bolt livrator;

	livrator.cod = cod;
	livrator.oreDeLucru = ore;
	livrator.program = program;

	livrator.automobil = (char*)malloc(strlen(automobil) + 1);
	strcpy(livrator.automobil, automobil);

	return livrator;
}

double salariu(const livrator_bolt* livrator) {
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

livrator_bolt* inserareVector(livrator_bolt* vector, int* dim, livrator_bolt livrator)
{
	livrator_bolt* aux = (livrator_bolt*)malloc(sizeof(livrator_bolt) * ((*dim) + 1));

	for (int i = 0; i < (*dim); i++)
	{
		aux[i] = vector[i];
	}
	aux[(*dim)] = livrator;
	(*dim)++;

	if (vector != NULL)
	{
		free(vector);
	}

	return aux;
}

livrator_bolt* citireVector(char* numeFisier, int* n)
{
	FILE* file = fopen(numeFisier, "r");

	livrator_bolt* vector = NULL;

	(*n) = 0;

	if (file)
	{
		char buffer[100];
		char delimiter[] = ",\n";

		while (fgets(buffer, 100, file) != NULL)
		{
			livrator_bolt livrator;

			char* token = strtok(buffer, delimiter);
			livrator.cod = atoi(token);

			token = strtok(NULL, delimiter);
			livrator.automobil = (char*)malloc(strlen(token) + 1);
			strcpy(livrator.automobil, token);

			token = strtok(NULL, delimiter);
			livrator.oreDeLucru = atof(token);

			token = strtok(NULL, delimiter);
			livrator.program = atoi(token);

			vector = inserareVector(vector, n, livrator);
		}

		fclose(file);
	}
	else
	{
		printf("\nFisierul %s nu a putut fi deschis. Vectorul este gol.", numeFisier);
	}

	return vector;
}

void salvareObiectInFisier(livrator_bolt livrator, char* numeFisier)
{
	FILE* file = fopen(numeFisier, "a");

	if (file)
	{
		fprintf(file, "%ld,%s,%.1f,%d", livrator.cod, livrator.automobil, livrator.oreDeLucru, livrator.program);

		fclose(file);
	}
	else
	{
		printf("\nFisierul %s nu a putut fi deschis.", numeFisier);
	}
}

void salvareVectorInFisier(char* numeFisier, livrator_bolt* vector, int dim)
{
	FILE* file = fopen(numeFisier, "w");

	if (!file)
	{
		printf("Eroare la accesarea fisierului.\n");
	}
	else
	{
		for (int i = 0; i < dim; i++)
		{
			fprintf(file, "%ld,%s,%.1f,%d\n", vector[i].cod, vector[i].automobil, vector[i].oreDeLucru, vector[i].program);
		}

		fclose(file);
	}
}

void afisareVector(livrator_bolt* vector, int dim)
{
	for (int i = 0; i < dim; i++)
		afisare(&vector[i]);
}

void main()
{
	livrator_bolt* vector = NULL;

	livrator_bolt livrator1 = constructor(1, "masina", 10, 0);
	//afisare(&livrator1);

	int dim = 0;

	vector = citireVector("livratori.txt", &dim);
	vector = inserareVector(vector, &dim, livrator1);

	afisareVector(vector, dim);

	salvareObiectInFisier(livrator1, "livratori.txt");

	vector = citireVector("livratori.txt", &dim);

	afisareVector(vector, dim);
	salvareVectorInFisier("livratoriVector.txt", vector, dim);
}