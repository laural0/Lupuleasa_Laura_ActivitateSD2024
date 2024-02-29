#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	long cod;

	char* automobil;

	float oreDeLucru;

	enum {
		deZi,

		deNoapte
	} program;
} livratorBolt;

double salariu(const livratorBolt* livrator);

void modificare(livratorBolt* livrator, float ore);

livratorBolt citire();

void afisare(const livratorBolt* livrator);

void stergeLivratorBolt(livratorBolt livrator);