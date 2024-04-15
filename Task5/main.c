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
		fprintf(file, "\n%ld,%s,%.1f,%d", livrator.cod, livrator.automobil, livrator.oreDeLucru, livrator.program);

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

typedef struct Nod Nod;
struct Nod
{
	livrator_bolt livrator;
	Nod* next;
};

Nod* citireListaDinFisier(Nod* lista, char* numeFisier)
{
	FILE* file = fopen(numeFisier, "r");

	if (!file)
	{
		printf("Fisierul %s nu a putut fi deschis.", numeFisier);
		return NULL;
	}
	else
	{
		char delimiter[] = ",\n";
		char buffer[100];

		while (fgets(buffer, 100, file) != NULL)
		{
			Nod* nodNou = malloc(sizeof(Nod));

			char* token = strtok(buffer, delimiter);
			nodNou->livrator.cod = atoi(token);

			token = strtok(NULL, delimiter);
			nodNou->livrator.automobil = (char*)malloc(strlen(token) + 1);
			strcpy(nodNou->livrator.automobil, token);

			token = strtok(NULL, delimiter);
			nodNou->livrator.oreDeLucru = atof(token);

			token = strtok(NULL, delimiter);
			nodNou->livrator.program = atoi(token);

			nodNou->next = NULL;

			if (lista == NULL)
			{
				lista = nodNou;
			}
			else
			{
				Nod* temp = lista;

				while (temp->next != NULL)
				{
					temp = temp->next;
				}

				temp->next = nodNou;
			}
		}

		fclose(file);

		return lista;
	}
}

void afisareLista(Nod* lista)
{
	for (Nod* nod = lista; nod != NULL; nod = nod->next)
	{
		afisare(&(nod->livrator));
	}
}

Nod* inserareDupaOre(char* numeFisier, Nod* lista)
{
	FILE* file = fopen(numeFisier, "r");

	if (!file)
	{
		printf("Fisierul nu a putut fi deschis\n");
		return NULL;
	}
	else
	{
		Nod* lista = NULL;

		char delimiter[] = ",\n";
		char buffer[100];

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

			Nod* nod = (Nod*)malloc(sizeof(Nod));
			nod->livrator = livrator;

			if (lista == NULL) //goala
			{
				nod->next = NULL;
				lista = nod;
			}
			else
			{
				if (lista->livrator.oreDeLucru > nod->livrator.oreDeLucru) //inceput
				{
					nod->next = lista;
					lista = nod;
				}
				else
				{
					Nod* temp = lista;
					while (temp->next != NULL && temp->next->livrator.oreDeLucru < nod->livrator.oreDeLucru)
					{
						temp = temp->next;
					}

					nod->next = temp->next;
					temp->next = nod;
				}
			}
		}
		fclose(file);

		return lista;
	}
}

Nod* interschimbare(Nod* lista, int poz1, int poz2) {
	int index = 0;
	Nod* nod1 = NULL;
	Nod* nod2 = NULL;
	Nod* prev1 = NULL;
	Nod* prev2 = NULL;

	for (Nod* nod = lista; nod != NULL; nod = nod->next) {
		if (poz1 == index) {
			nod1 = nod;
		}
		if (poz2 == index) {
			nod2 = nod;
		}
		if (nod1 != NULL && nod2 != NULL) {
			break;
		}
		if (nod1 == NULL) {
			prev1 = nod;
		}
		if (nod2 == NULL) {
			prev2 = nod;
		}
		index++;
	}

	if (nod1 == NULL || nod2 == NULL) {
		printf("Pozitiile sunt invalide.\n");
		return lista;
	}

	if (poz1 + 1 == poz2 || poz2 + 1 == poz1) {
		if (poz1 + 1 == poz2) {
			nod1->next = nod2->next;
			nod2->next = nod1;
		}
		else {
			nod2->next = nod1->next;
			nod1->next = nod2;
		}
		if (prev1 == NULL) {
			lista = nod2;
		}
		else if (prev2 == NULL) {
			lista = nod1;
		}
	}
	else {
		if (prev1 != NULL) {
			prev1->next = nod2;
		}
		else {
			lista = nod2;
		}
		if (prev2 != NULL) {
			prev2->next = nod1;
		}
		else {
			lista = nod1;
		}

		Nod* temp = nod2->next;
		nod2->next = nod1->next;
		nod1->next = temp;
	}

	return lista;
}

void dezalocareLivrator(livrator_bolt* livrator_bolt)
{
	if (livrator_bolt->automobil != NULL)
	{
		free(livrator_bolt->automobil);
		livrator_bolt->automobil = NULL;
	}
}
void dezalocareLista(Nod** lista)
{
	Nod* temp;

	while ((*lista) != NULL)
	{
		temp = (*lista);
		(*lista) = (*lista)->next;
		dezalocareLivrator(&(temp)->livrator);
		free(temp);
		temp = NULL;
	}
}

void main()
{
	livrator_bolt* vector = NULL;

	int dim = 0;

	vector = citireVector("livratori.txt", &dim);

	// afisareVector(vector, dim);

	Nod* lista = NULL;

	// lista = citireListaDinFisier(lista, "livratori.txt");
	//
	// afisareLista(lista);

	lista = inserareDupaOre("livratori.txt", lista);

	afisareLista(lista);

	lista = interschimbare(lista, 0, 1);
	printf("-------------------------------------\n");

	afisareLista(lista);

	dezalocareLista(&lista);

	afisareLista(lista);
}