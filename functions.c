#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

int getRandomNumber(int min, int max) {
    int t = 0;
    
    t = rand() % (max - min + 1) + min;

    return t;

}

CHAMPION createChampion() {
    //return (CHAMPION)getRandomNumber(0,2);
    CHAMPION c;
    switch(getRandomNumber(0,2)) {
        case 0:
            c = MAGE;
            break;
        case 1:
            c = FIGHTER;
            break;
        case 2:
            c = TANK;
            break;
        default: 
            printf("Unable to generate character\n");
            c = MAGE;
    }
    return c;
}

int getChampionPoints(CHAMPION c) {
    int points;
    switch(c) {
        case MAGE:
            points = getRandomNumber(1, 8);
            break;
        case FIGHTER:
            points = getRandomNumber(3, 7);
            break;
        case TANK:
            points = getRandomNumber(5, 9);
            break;
        default:
            points = 0;
    }
    return points;
}

void printChampion(CHAMPION c) {
    switch(c) {
        case MAGE:
            printf("MAGE");
            break;
        case FIGHTER:
            printf("FIGHTER");
            break;
        case TANK:
            printf("TANK");
            break;
    }
}

void playRound(int* p1_total, int* p2_total, CHAMPION c1, int c1_points, CHAMPION c2, int c2_points) {
    switch(c1) {
        //switch statement for player 1
        case MAGE: //if player 1 is MAGE
            switch(c2) { //switch statement for player 2
            case MAGE: //if player 2 is MAGE
                    if(c1_points > c2_points) {
                        *p1_total += c1_points;
                        *p2_total -= c2_points;
                        printf("Player 1 (MAGE) wins and gains their current points\n");
                        printf("Player 2 (MAGE) loses and loses heir current points\n");
                    } else if(c2_points > c1_points){
                        *p2_total += c2_points;
                        *p1_total -= c1_points;
                        printf("Player 1 (MAGE) loses and loses their current points\n");
                        printf("Player 2 (MAGE) wins and gains their current points\n");
                    } else {
                        printf("Tie\n");
                    }
                    break;
            case FIGHTER: //if player 2 is FIGHTER
                    if(c1_points > c2_points) {
                        *p1_total += c1_points;
                        printf("Player 1 (MAGE) wins and gains their current points\n");
                        printf("Player 2 (FIGHTER) loses without penalty\n");
                    } else if(c2_points > c1_points) {
                        *p1_total -= c1_points;
                        printf("Player 1 (MAGE) loses and loses their current points\n");
                        printf("Player 2 (FIGHTER) wins without reward\n");
                    } else {
                        printf("Tie\n");
                    }
                    break;
            case TANK: //if player 2 is TANK
                    *p1_total += c1_points;
                    *p2_total -= c2_points;
                    printf("Player 1 (MAGE) wins and gains their current points\n");
                    printf("Player 2 (TANK) loses and loses their current points\n");
                    break;
            }
            break;

        case FIGHTER: //if player 1 is FIGHTER
            switch(c2) {
                //switch statement for player 2
            case FIGHTER: //if player 2 is FIGHTER
                    *p1_total += c1_points;
                    *p2_total += c2_points;
                    printf("Player 1 (FIGHTER) wins and gains their current points\n");
                    printf("Player 2 (FIGHTER) wins and gains their current points\n");
                    break;

            case TANK: //if player 2 is TANK
                    *p1_total += c1_points;
                    printf("Player 1 (FIGHTER) wins and gains their current points\n");
                    printf("Player 2 (TANK) loses with no penalty\n");
                    break;
            case MAGE:
                    if (c1_points > c2_points) {
                        *p2_total -= c2_points;
                        printf("Player 1 (FIGHTER) gains no reward\n");
                        printf("Player 2 (MAGE) loses their current points\n");
                    } else if (c2_points > c1_points) {
                        *p2_total += c2_points;
                        printf("Player 1 (FIGHTER) loses with no penalty\n");
                        printf("Player 2 (MAGE) gains their current points\n");
                    } else {
                        printf("Tie\n");
                    }
                    break;
            default:
                    break;
            }
            break;

        case TANK: //if player 1 is TANK
            switch(c2) {
                //switch statement for player 2
            case TANK: //if player 2 is TANK
                    printf("Player 1 (TANK) retains their points\n");
                    printf("Player 2 (TANK) retains their points\n");
                    printf("Nothing happens\n");
                    break;
            case FIGHTER:
                    *p2_total += c2_points;
                    printf("Player 1 (TANK) retains their points\n");
                    printf("Player 2 (FIGHTER) wins and gains their current points\n");
                    break;
            case MAGE:
                    *p1_total -= c1_points;
                    *p2_total += c2_points;
                    printf("Player 1 (TANK) loses their current points\n");
                    printf("Player 2 (MAGE) gains their current points\n");
                    break;
            default:
                    break;
            }
            break;
        default:
            printf("Champion not found. Fix CHAMPION logic\n");
            break;
    }
}