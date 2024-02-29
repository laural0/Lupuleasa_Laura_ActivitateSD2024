#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "task2.h"

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