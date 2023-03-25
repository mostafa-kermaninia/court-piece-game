#include <stdio.h>
#include "playGround.h"
#include "intToSymbol.h"

#define baseForm -1

void drawPlayGround(int P1num, char P1symbol, int P2num, char P2symbol, int P3num, char P3symbol, int P4num, char P4symbol, int team1Score, int team2Score)
{
    // the play ground
    // base form (there is not any cards on the ground)
    if (P1num == baseForm)
    {
        printf("                              P3\n\
     ----------------------------------------------------    Team 1: %d\n",
               team1Score);
        for (int i = 1; i < 17; i++)
        {
            if (i == 9)
            {
                printf("   P2|\t\t\t\t\t\t\t|P4\n");
            }

            printf("     |\t\t\t\t\t\t\t|\n");
        }
        printf("     ----------------------------------------------------    Team 2: %d\n\
                              P1\n",
               team2Score);
    }

    // main form
    else
    {
        printf("                              P3\n\
     ----------------------------------------------------    Team 1: %d\n\
     |                        %c%2d                       |\n",
               team1Score, P3symbol, P3num);
        for (int i = 1; i < 17; i++)
        {
            if (i == 9)
            {
                printf("   P2|  %c%2d\t\t\t\t\t   %c%2d  |P4\n", P2symbol, P2num, P4symbol, P4num);
            }

            printf("     |\t\t\t\t\t\t\t|\n");
        }
        printf("     |                        %c%2d                       |\n\
     ----------------------------------------------------    Team 2: %d\n\
                              P1\n",
               P1symbol, P1num, team2Score);
    }
}
void drawHandCards(int playerCards[4][11], int team1Wins, int team2Wins)
{

    char symbols[11];
    int nums[11], index = 0;

    // convert 2D cards Array to two 1D array for symbols and nums
    for (int index = 0; index < 11; index++)
    {
        symbols[index] = '-';
        nums[index] = 0;
    }
    for (int symbol = 0; symbol < 4; symbol++)
    {
        for (int cardNum = 0; cardNum < 11; cardNum++)
        {
            if (playerCards[symbol][cardNum])
            {
                if (playerCards[symbol][cardNum] == -1)
                {
                    symbols[index] = '-';
                    nums[index] = 0;
                }
                else
                {
                    symbols[index] = intToSymbol(symbol);
                    nums[index] = cardNum + 1;
                }
                index++;
            }
        }
    }
    // draw hand cards
    printf(
        "       -------------------------------------------------------- \n\
symbol |  %c |  %c |  %c |  %c |  %c |  %c |  %c |  %c |  %c |  %c |  %c |  \n\
       --------------------------------------------------------  \n\
number | %2d | %2d | %2d | %2d | %2d | %2d | %2d | %2d | %2d | %2d | %2d |  \n\
       --------------------------------------------------------  \n\
          0    1    2    3    4    5    6    7    8    9    10    \n",
        symbols[0], symbols[1], symbols[2], symbols[3], symbols[4], symbols[5],
        symbols[6], symbols[7], symbols[8], symbols[9], symbols[10],
        nums[0], nums[1], nums[2], nums[3], nums[4], nums[5],
        nums[6], nums[7], nums[8], nums[9], nums[10]);

    // print teams' setScores
    printf("\tTEAM1 SETSCORES : %d  \t\t  TEAM2 SETSCORES : %d \n", team1Wins, team2Wins);
}
