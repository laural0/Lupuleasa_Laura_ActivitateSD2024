#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "task1.h"

livratorBolt* copiereObiecte(livratorBolt* vectObiecte, int lungime, float oreMinime);

livratorBolt* concatenareVectori(livratorBolt* vector1, int lungime1, livratorBolt* vector2, int lungime2);

void afisareVector(livratorBolt* vector, int lungime);