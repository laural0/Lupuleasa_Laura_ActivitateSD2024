#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Santier Santier;
typedef struct Nod Nod;

struct Santier
{
	char* numeProiect;
	int numarMuncitori;
	float suprafata;
};

struct Nod
{
	Santier santier;
	Nod* next;
};

Santier santier_initializare(const char* numeProiect, int numarMuncitori, float suprafata)
{
	Santier santier;
	santier.numeProiect = (char*)malloc(strlen(numeProiect) + 1);
	strcpy(santier.numeProiect, numeProiect);

	santier.numarMuncitori = numarMuncitori;
	santier.suprafata = suprafata;

	return santier;
}

Nod* santier_inserare(Santier santier, Nod* lista) {
	Nod* nod = (Nod*)malloc(sizeof(Nod));
	nod->santier = santier;

	nod->next = lista;

	return nod;
}

void santier_afisare(Santier santier)
{
	printf("Santierul %s are %d muncitori si %.2f m^2 suprafata\n",
		santier.numeProiect, santier.numarMuncitori, santier.suprafata);
}

void lista_afisare(Nod* lista)
{
	while (lista != NULL)
	{
		santier_afisare(lista->santier);
		lista = lista->next;
	}
}

int santier_sumaMuncitori(Nod* lista)
{
	int total = 0;

	while (lista != NULL)
	{
		total += lista->santier.numarMuncitori;
		lista = lista->next;
	}

	return total;
}

void lista_stergere(Nod** lista)
{
	while ((*lista) != NULL)
	{
		free((*lista)->santier.numeProiect);
		Nod* aux = (*lista)->next;

		free(*lista);
		(*lista) = aux;
	}
	(*lista) = NULL;
}

float santier_densitateMuncitori(Santier santier)
{
	if (santier.suprafata > 0)
	{
		return santier.numarMuncitori / santier.suprafata;
	}

	else return 0;
}

char* santier_numeSantierDensitateMaxima(Nod* lista)
{
	float max = 0;
	char* aux = NULL;

	while (lista != NULL)
	{
		if (santier_densitateMuncitori(lista->santier) > max)
		{
			max = santier_densitateMuncitori(lista->santier);
			aux = lista->santier.numeProiect;
		}
		lista = lista->next;
	}

	if (aux != NULL)
	{
		char* numeProiect = (char*)malloc(strlen(aux) + 1);
		strcpy(numeProiect, aux);
		return numeProiect;
	}
	else return NULL;
}

void main()
{
	Nod* lista = NULL;

	Santier santier1 = santier_initializare("Santier 1", 10, 300.0);
	Santier santier2 = santier_initializare("Santier 2", 20, 900.0);
	Santier santier3 = santier_initializare("Santier 3", 30, 800.0);

	lista = santier_inserare(santier1, lista);
	lista = santier_inserare(santier2, lista);
	lista = santier_inserare(santier3, lista);

	lista_afisare(lista);

	printf("\n %s este santierul cu densitatea maxima de muncitori.", santier_numeSantierDensitateMaxima(lista));

	// lista_stergere(lista);

	// lista_afisare(lista);
}