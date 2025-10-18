#include <stdio.h>
#include "functions.h"
#include <time.h>
#include <stdlib.h>


//overiew: create a turn based game that is played between 2 computers, where they battle each other's champions

/* rules:
      1. a champion is created each game
        - champions are created with a 33.3% probability for 3 characters: MAGE, FIGHTER, TANK
        - points:
            > MAGE: random num between 1 and 8 inclusive
            > FIGHTER: random num between 3 and 7 inclusive
            > TANK: random num between 5 and 9 inclusive
    2. after both players get their characters, a fight happens and the outcome is based on this
        - MAGE v.s. MAGE:
            > player with more points wins
            > winner: gains current points
            > loser: loses all points
            > tie: nothing
        - MAGE v.s. Fighter:
            > player with more points wins
            > if mage wins: gains their current points, fighter gets NO penalty
            > if figher wins: no reward, but mage loses all their points
            > tie: nothing
        - MAGE v.s. Tank:
            > if mage wins: gains their current points
            > if tank wins: loses their current points
        - Fighter v.s. Fighter:
            > both players win and gain all their current points
        - Fighter v.s. Tank:
            > if fighter wins: gains current points
            > if tank loses: no penalty
        - Tank v.s. Tank
            > nothing happens at all
*/
int main() {

    srand(time(NULL));
    int rounds = 0;
    CHAMPION c1;
    CHAMPION c2;

    printf("Welcome to Battleground!\n");
    printf("Select the number of rounds you would like to play : ");
    scanf("%d", &rounds);

    int p1total = 0;
    int p2total = 0;
    for(int i = 1; i <= rounds; i++) {
        printf("\n");
        printf("ROUND %d\n", i);
        printf("-----------\n");

        printf("Player points at the start of the round: P1 --> %d and P2 --> %d\n", p1total, p2total);
        c1 = createChampion();
        c2 = createChampion();

        int c1_points = getChampionPoints(c1);
        int c2_points = getChampionPoints(c2);

        printf("P1: ");
        printChampion(c1);
        printf("-%d vs P2: ", c1_points);
        printChampion(c2);
        printf("-%d\n", c2_points);
        
        playRound(&p1total, &p2total, c1, c1_points, c2, c2_points);
        printf("Player points at the end of the round --> P1: %d  P2: %d", p1total, p2total);
        printf("\n");
    }

    printf("------\n");
    printf("Game Over!\n");

    if(p1total > p2total) {
        printf("P1 Won\n");
    } else if (p1total < p2total) {
        printf("P2 Won\n");
    } else {
        printf("It's a tie!\n");
    }

}