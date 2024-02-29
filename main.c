#include "task2.h"

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