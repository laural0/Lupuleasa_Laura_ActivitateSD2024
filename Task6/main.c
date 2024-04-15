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

void dezalocareLivrator(livrator_bolt* livrator_bolt)
{
	if (livrator_bolt->automobil != NULL)
	{
		free(livrator_bolt->automobil);
		livrator_bolt->automobil = NULL;
	}
}

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

typedef struct Nod Nod;
struct Nod
{
	Nod* next;
	Nod* prev;
	livrator_bolt info;
};

typedef struct ListaDubla Ld;
struct ListaDubla
{
	Nod* prim;
	Nod* ultim;
};

void inserareLaInceput(Ld* lista, Nod* nod)
{
	if (lista->prim == NULL)
	{
		lista->ultim = nod;
		lista->prim = nod;
		nod->next = NULL;
		nod->prev = NULL;
	}
	else
	{
		lista->prim->prev = nod;
		nod->next = lista->prim;
		nod->prev = NULL;
		lista->prim = nod;
	}
}

void inserareLaFinal(Ld* lista, Nod* nod)
{
	if (lista->ultim == NULL)
	{
		lista->ultim = nod;
		lista->prim = nod;
		nod->next = NULL;
		nod->prev = NULL;
	}
	else
	{
		lista->ultim->next = nod;
		nod->prev = lista->ultim;
		nod->next = NULL;
		lista->ultim = nod;
	}
}

Nod* cautareNod(Nod* cap, int poz)
{
	if (cap == NULL)
	{
		printf("Lista este goala. Nu se poate cauta nodul.\n");
		return NULL;
	}

	if (poz < 0)
	{
		printf("Pozitia este incorecta.\n");
		return NULL;
	}

	if (poz == 0)
		return cap;

	int index = 0;

	while (cap != NULL)
	{
		if (index == poz) return cap;

		cap = cap->next;
		index++;
	}

	printf("Elementul nu exista in lista.\n");
	return NULL;
}

void inserareLaMijloc(Ld* lista, Nod* nod, int poz)
{
	Nod* prev_nod = cautareNod(lista->prim, poz - 1);

	Nod* nod_la_poz = prev_nod->next;

	nod->prev = prev_nod;
	nod->next = nod_la_poz;

	prev_nod->next = nod;

	nod_la_poz->prev = nod;
}

void stergeNod(Nod* nod)
{
	nod->next->prev = nod->prev;
	nod->prev->next = nod->next;

	dezalocareLivrator(&nod->info);
	free(nod);
}

void stergeNodLaPozitie(Ld* lista, int poz)
{
	if (poz == 0)
	{
		Nod* victima = lista->prim;

		lista->prim = lista->prim->next;
		lista->prim->prev = NULL;

		dezalocareLivrator(&victima->info);
		free(victima);
	}
	else
	{
		Nod* nod = cautareNod(lista->prim, poz);

		stergeNod(nod);
	}
}

void inserareDupaOre(Ld* lista, Nod* nod)
{
	if (lista->prim == NULL)
	{
		inserareLaInceput(lista, nod);
	}
	else
	{
		if (lista->prim->info.oreDeLucru > nod->info.oreDeLucru)
		{
			inserareLaInceput(lista, nod);
		}
		else
			if (lista->ultim->info.oreDeLucru < nod->info.oreDeLucru)
				inserareLaFinal(lista, nod);
			else
			{
				int index = 0;
				Nod* cap = lista->prim;

				while (cap->next != NULL && cap->next->info.oreDeLucru < nod->info.oreDeLucru)
				{
					index++;
					cap = cap->next;
				}

				inserareLaMijloc(lista, nod, index + 1);
			}
	}
}

void inserareInListaDinFisierOrdonat(char* numeFisier, Ld* lista)
{
	FILE* file = fopen(numeFisier, "r");

	if (!file)
	{
		printf("Fisierul nu a putut fi deschis");
	}
	else
	{
		char delimiter[] = ",\n";
		char buffer[100];
		livrator_bolt livrator;

		while (fgets(buffer, 100, file))
		{
			char* token = strtok(buffer, delimiter);

			livrator.cod = atoi(token);

			token = strtok(NULL, delimiter);
			livrator.automobil = (char*)malloc(strlen(token) + 1);
			strcpy(livrator.automobil, token);

			token = strtok(NULL, delimiter);
			livrator.oreDeLucru = atof(token);

			token = strtok(NULL, delimiter);
			livrator.program = atoi(token);

			Nod* nodNou = malloc(sizeof(Nod));
			nodNou->info = livrator;

			inserareDupaOre(lista, nodNou);
		}

		fclose(file);
	}
}

void inserareInListaDInFisier(char* numeFisier, Ld* lista)
{
	FILE* file = fopen(numeFisier, "r");

	if (!file)
	{
		printf("Fisierul nu a putut fi deschis\n");
	}
	else
	{
		char delimiter[] = ",\n";
		char buffer[100];
		livrator_bolt livrator;

		while (fgets(buffer, 100, file) != NULL)
		{
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
			nod->info = livrator;

			inserareLaFinal(lista, nod);
		}

		fclose(file);
	}
}

void afisareLista(Ld* lista)
{
	for (Nod* nod = lista->prim; nod != NULL; nod = nod->next)
	{
		afisare(&(nod->info));
	}
}

void afisareListaInvers(Ld* lista)
{
	for (Nod* nod = lista->ultim; nod != NULL; nod = nod->prev)
	{
		afisare(&(nod->info));
	}
}

typedef struct Nod_ls Ls;
struct Nod_ls
{
	Ls* next;
	livrator_bolt livrator;
};

Ls* salvareInListaSimpla(Ld* lista)
{
	Ls* listaSimpla = NULL;

	Nod* cap = lista->prim;

	while (cap != NULL)
	{
		if (cap->info.program == 0) {//daca este program de zi
			Ls* nodNou = (Ls*)malloc(sizeof(Ls));

			livrator_bolt livrator = constructor(
				cap->info.cod,
				cap->info.automobil,
				cap->info.oreDeLucru,
				cap->info.program);

			nodNou->livrator = livrator;
			nodNou->next = NULL;

			if (listaSimpla == NULL)
			{
				listaSimpla = nodNou;
			}
			else
			{
				Ls* current = listaSimpla;

				while (current->next != NULL)
				{
					current = current->next;
				}

				current->next = nodNou;
			}
		}

		cap = cap->next;
	}

	return listaSimpla;
}

void afisareListaSimpla(Ls* lista)
{
	for (Ls* nod = lista; nod != NULL; nod = nod->next)
	{
		afisare(&(nod->livrator));
	}
}

void interschimbaElemente(Ld* lista, int poz1, int poz2)
{
	if (poz1 < 0 || poz2 < 0 || lista == NULL)
	{
		printf("Pozitii sau lista invalida.\n");
	}
	else
	{
		Nod* nod_poz1 = cautareNod(lista->prim, poz1);
		Nod* nod_poz2 = cautareNod(lista->prim, poz2);

		livrator_bolt aux = nod_poz1->info;
		nod_poz1->info = nod_poz2->info;
		nod_poz2->info = aux;
	}
}

void main()
{
	Ld listaL;
	listaL.prim = NULL;
	listaL.ultim = NULL;

	inserareInListaDInFisier("livratori.txt", &listaL);
	//
	afisareLista(&listaL);

	printf("___________________________\n");

	interschimbaElemente(&listaL, 0, 4);
	afisareLista(&listaL);

	// stergeNodLaPozitie(&listaL, 0);

	// printf("_________________________\n");

	// afisareLista(&listaL);

	// Nod* nodTest = (Nod*)malloc(sizeof(Nod));
	//
	// nodTest->info = constructor(999, "test", 1, 1);
	//
	// inserareLaMijloc(&listaL, nodTest, 2);

	// inserareInListaDinFisierOrdonat("livratori.txt", &listaL);
	//
	// afisareLista(&listaL);
	//
	// printf("--------------------------\n");
	//
	// afisareListaInvers(&listaL);

	// Ls* listaSimpla;

	// listaSimpla = salvareInListaSimpla(&listaL);

	// afisareListaSimpla(listaSimpla);
}