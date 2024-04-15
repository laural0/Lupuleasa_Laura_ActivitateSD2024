#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Cladire Cladire;
struct Cladire
{
	int an;
	long id;
	char* denumire;
};

Cladire* constructor(int an, long id, char* denumire)
{
	Cladire* cladire = (Cladire*)malloc(sizeof(Cladire));

	cladire->an = an;
	cladire->id = id;

	cladire->denumire = (char*)malloc(strlen(denumire) + 1);
	strcpy(cladire->denumire, denumire);

	return cladire;
}

typedef struct Nod Nod;
struct Nod
{
	Nod* next;
	Cladire info;
};

typedef struct HashMap hash_map;
struct HashMap
{
	Nod** vector;
	int dimensiune;
};

int hash(int an, int dimensiune, const char* denumire)
{
	if (dimensiune > 0)
	{
		int rez = an * strlen(denumire);

		return rez % dimensiune;
	}

	return -1;
}

hash_map initializareHashMap(int dimensiune)
{
	hash_map hashMap;

	hashMap.dimensiune = dimensiune;

	hashMap.vector = (Nod**)malloc(sizeof(Nod*) * dimensiune);

	for (int i = 0; i < dimensiune; i++)
	{
		hashMap.vector[i] = NULL;
	}

	return hashMap;
}

void inserareInVector(Nod** vector, Cladire cladire)
{
	Nod* elementNou = (Nod*)malloc(sizeof(Nod));
	elementNou->info = cladire;
	elementNou->next = NULL;

	if (*vector)
	{
		Nod* temp = *vector;

		while (temp->next != NULL)
		{
			temp = temp->next;
		}

		temp->next = elementNou;
	}
	else
	{
		*vector = elementNou;
	}
}

void adaugareInHashMap(hash_map hashMap, Cladire cladire)
{
	if (hashMap.dimensiune > 0)
	{
		int pozitie = hash(cladire.an, hashMap.dimensiune, cladire.denumire);

		inserareInVector(&(hashMap.vector[pozitie]), cladire);
	}
}

void afisareCladire(Cladire cladire)
{
	printf("Cladirea %-15s cu id-ul %-2ld este construita in anul %-6d\n",
		cladire.denumire, cladire.id, cladire.an);
}

void afisareLista(Nod* vector)
{
	for (Nod* nod = vector; nod != NULL; nod = nod->next)
	{
		afisareCladire(nod->info);
	}
}

void afisareHashMap(hash_map hashMap)
{
	for (int i = 0; i < hashMap.dimensiune; i++)
	{
		if (hashMap.vector[i] != NULL)
		{
			printf("Cluster %d\n", i + 1);
			afisareLista(hashMap.vector[i]);
		}
	}
}

void dezalocareCladire(Cladire cladire)
{
	if (cladire.denumire != NULL)
	{
		free(cladire.denumire);
		cladire.denumire = NULL;
	}
}

void dezalocareVector(Nod** vector)
{
	Nod* temp = (*vector);

	while (temp != NULL)
	{
		Nod* aux = temp;
		temp = temp->next;

		dezalocareCladire(aux->info);
		free(aux);
	}
}

void dezalocareHashMap(hash_map* hashMap)
{
	for (int i = 0; i < (*hashMap).dimensiune; i++)
	{
		if ((*hashMap).vector[i] != NULL)
		{
			dezalocareVector((&(*hashMap).vector[i]));
		}
	}

	free(hashMap->vector);
}

void main()
{
	// Cladirea A, 1, 2000
	// 	Cladirea B, 2, 2010
	// 	Cladirea C, 3, 1995
	// 	Cladirea D, 4, 2022
	// 	Cladirea E, 5, 2005

	Cladire* cladire1 = constructor(2000, 1, "Cladirea A");
	Cladire* cladire2 = constructor(2010, 2, "Cladirea B");
	Cladire* cladire3 = constructor(2009, 3, "Racari 51");

	hash_map hashMap;

	hashMap = initializareHashMap(5);

	adaugareInHashMap(hashMap, *cladire1);
	adaugareInHashMap(hashMap, *cladire2);
	adaugareInHashMap(hashMap, *cladire3);

	afisareHashMap(hashMap);

	dezalocareHashMap(&hashMap);
}