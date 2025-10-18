#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>

typedef enum {MAGE, FIGHTER, TANK} CHAMPION;

int getRandomNumber(int min, int max);
CHAMPION createChampion(void);
int getChampionPoints(CHAMPION c);
void printChampion(CHAMPION c);
void playRound(int* p1_total, int* p2_total, CHAMPION c1, int c1_points, CHAMPION c2, int c2_points);


#endif

