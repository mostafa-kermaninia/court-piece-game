//  gcc main.c botsCardSelector.c intToSymbol.c judge.c maxAndMin.c playGround.c userCardReciever.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#include "botsCardSelector.h"
#include "intToSymbol.h"
#include "judge.h"
#include "maxAndMin.h"
#include "playGround.h"
#include "userCardReciever.h"

// define booleans
#define False 0
#define True 1
// guid for some Arrays indexes and base version of functions
#define NUMBER 0
#define SYMBOL 1
#define baseForm -1
// define end of set and game
#define MAXSCORE 6
#define MAXSET 2

void shuffle_card(int *card);

int main(void)
{
    int set = 1, maxScore, team1Score, team2Score, team1Wins = 0, team2Wins = 0;
    // play the set
    while (set <= MAXSET)
    {
        // Shuffle the cards
        int card[44];
        shuffle_card(card);
        int cards[4][11], P1cards[4][11], P2cards[4][11], P3cards[4][11], P4cards[4][11];
        for (int symbol = 0; symbol < 4; symbol++)
        {
            for (int cardNum = 0; cardNum < 11; cardNum++)
            {
                cards[symbol][cardNum] = cardNum + 1;
                P1cards[symbol][cardNum] = 0;
                P2cards[symbol][cardNum] = 0;
                P3cards[symbol][cardNum] = 0;
                P4cards[symbol][cardNum] = 0;
            }
        }

        // start the game
        drawPlayGround(baseForm, '-', 0, '-', 0, '-', 0, '-', 0, 0);
        drawHandCards(P1cards, team1Wins, team2Wins);
        char wannaStart;
        int ansIsValid = False;
        while (ansIsValid == False)
        {
            printf("Do you want to start this set ?(Y/N)\n");
            scanf("%c", &wannaStart);
            getchar(); // for cleaning buffer from the ENTER we pressed after previous scanf

            if (wannaStart == 'N' || wannaStart == 'n')
            {
                printf("Ok, GO!\n");
                getch();
                return 0;
            }
            else if (wannaStart == 'Y' || wannaStart == 'y')
            {
                printf("Let's Go!\n");
                ansIsValid = True;
            }
            else
            {
                printf("Enter a valid answer!\n");
            }
        }

        // Start first round of dealing cards
        for (int i = 0; i < 5; i++)
        {
            P1cards[card[i] / 11][card[i] % 11] = cards[card[i] / 11][card[i] % 11];
        }

        // Specify BAKHSH NAMEH
        drawPlayGround(baseForm, '-', 0, '-', 0, '-', 0, '-', 0, 0);
        drawHandCards(P1cards, team1Wins, team2Wins);
        char bakhshNameh;
        printf("What is the BAKHSH NAMEH ?(A, B, C or D)\n");

        // recieve BAKHSH NAMEH and Check validity of it
        ansIsValid = False;
        while (ansIsValid == False)
        {
            ansIsValid = True;
            scanf("%c", &bakhshNameh);
            getchar(); // for cleaning buffer from the ENTER we pressed after previous scanf

            if (bakhshNameh != 'A' && bakhshNameh != 'B' && bakhshNameh != 'C' && bakhshNameh != 'D')
            {
                printf("You chose invalid card Type, choose again :\n");
                ansIsValid = False;
            }
        }
        printf("%c will be the BAKHSH NAMEH.\n", bakhshNameh);
        int BAKHSHNAMEH;
        switch (bakhshNameh)
        {
        case 'A':
            BAKHSHNAMEH = 0;
            break;
        case 'B':
            BAKHSHNAMEH = 1;
            break;
        case 'C':
            BAKHSHNAMEH = 2;
            break;
        case 'D':
            BAKHSHNAMEH = 3;
            break;
        }

        // continue first round of dealing cards
        for (int i = 5; i < 20; i++)
        {
            if (i < 10)
            {
                P2cards[card[i] / 11][card[i] % 11] = cards[card[i] / 11][card[i] % 11];
            }
            if (i >= 10 && i < 15)
            {
                P3cards[card[i] / 11][card[i] % 11] = cards[card[i] / 11][card[i] % 11];
            }
            if (i >= 15)
            {
                P4cards[card[i] / 11][card[i] % 11] = cards[card[i] / 11][card[i] % 11];
            }
        }

        // second round of dealing cards
        printf("Enter something for deal 4 more cards!\n");
        getch();

        for (int i = 20; i < 36; i++)
        {
            if (i < 24)
            {
                P1cards[card[i] / 11][card[i] % 11] = cards[card[i] / 11][card[i] % 11];
            }
            if (i >= 24 && i < 28)
            {
                P2cards[card[i] / 11][card[i] % 11] = cards[card[i] / 11][card[i] % 11];
            }
            if (i >= 28 && i < 32)
            {
                P3cards[card[i] / 11][card[i] % 11] = cards[card[i] / 11][card[i] % 11];
            }
            if (i >= 32)
            {
                P4cards[card[i] / 11][card[i] % 11] = cards[card[i] / 11][card[i] % 11];
            }
        }
        drawPlayGround(baseForm, '-', 0, '-', 0, '-', 0, '-', 0, 0);
        drawHandCards(P1cards, team1Wins, team2Wins);

        // third round of dealing cards
        printf("Enter something for deal 2 last cards!\n");
        getch();

        for (int i = 36; i < 44; i++)
        {
            if (i < 38)
            {
                P1cards[card[i] / 11][card[i] % 11] = cards[card[i] / 11][card[i] % 11];
            }
            if (i >= 38 && i < 40)
            {
                P2cards[card[i] / 11][card[i] % 11] = cards[card[i] / 11][card[i] % 11];
            }
            if (i >= 40 && i < 42)
            {
                P3cards[card[i] / 11][card[i] % 11] = cards[card[i] / 11][card[i] % 11];
            }
            if (i >= 42)
            {
                P4cards[card[i] / 11][card[i] % 11] = cards[card[i] / 11][card[i] % 11];
            }
        }
        drawPlayGround(baseForm, '-', 0, '-', 0, '-', 0, '-', 0, 0);
        drawHandCards(P1cards, team1Wins, team2Wins);

        // Zeroing teams scores and start the set with user
        team1Score = 0, team2Score = 0, maxScore = 0;
        int starter = 1;

        // play the set
        while (maxScore != MAXSCORE)
        {
            // play the round
            int P1Choise[2], P2Choise[2], P3Choise[2], P4Choise[2], baseSymbol[1], groundSymbol;
            switch (starter)
            {
            case 1:
            {
                // first player
                userReciever(P1cards, P1Choise, baseForm);
                groundSymbol = P1Choise[SYMBOL];  // we use ground Symbol int just in this case
                baseSymbol[0] = P1Choise[SYMBOL]; // we use base Symbol array to build a global value and use it out of switchcase
                // second player
                secondCardFinder(P2cards, P2Choise, P1Choise, BAKHSHNAMEH, groundSymbol);
                // third player
                thirdCardFinder(P3cards, P3Choise, P1Choise, P2Choise, BAKHSHNAMEH, groundSymbol);
                // forth player
                forthCardFinder(P4cards, P4Choise, P1Choise, P2Choise, P3Choise, BAKHSHNAMEH, groundSymbol);
                break;
            }
            case 2:
            {
                // first player
                firstCardFinder(P2cards, P2Choise, BAKHSHNAMEH);
                groundSymbol = P2Choise[SYMBOL];  // we use ground Symbol int just in this case
                baseSymbol[0] = P2Choise[SYMBOL]; // we use base Symbol array to build a global value and use it out of switchcase
                // second player
                secondCardFinder(P3cards, P3Choise, P2Choise, BAKHSHNAMEH, groundSymbol);
                // third player
                thirdCardFinder(P4cards, P4Choise, P2Choise, P3Choise, BAKHSHNAMEH, groundSymbol);
                // forth player
                drawPlayGround(0, ' ', P2Choise[NUMBER], intToSymbol(P2Choise[SYMBOL]), P3Choise[NUMBER], intToSymbol(P3Choise[SYMBOL]), P4Choise[NUMBER], intToSymbol(P4Choise[SYMBOL]), team1Score, team2Score);
                drawHandCards(P1cards, team1Wins, team2Wins);
                userReciever(P1cards, P1Choise, groundSymbol);
                break;
            }
            case 3:
            {
                // first player
                firstCardFinder(P3cards, P3Choise, BAKHSHNAMEH);
                groundSymbol = P3Choise[SYMBOL];  // we use ground Symbol int just in this case
                baseSymbol[0] = P3Choise[SYMBOL]; // we use base Symbol array to build a global value and use it out of switchcase
                // second player
                secondCardFinder(P4cards, P4Choise, P3Choise, BAKHSHNAMEH, groundSymbol);
                // third player
                drawPlayGround(0, ' ', 0, ' ', P3Choise[NUMBER], intToSymbol(P3Choise[SYMBOL]), P4Choise[NUMBER], intToSymbol(P4Choise[SYMBOL]), team1Score, team2Score);
                drawHandCards(P1cards, team1Wins, team2Wins);
                userReciever(P1cards, P1Choise, groundSymbol);
                // forth player
                forthCardFinder(P2cards, P2Choise, P3Choise, P4Choise, P1Choise, BAKHSHNAMEH, groundSymbol);
                break;
            }
            case 4:
            {
                // first player
                firstCardFinder(P4cards, P4Choise, BAKHSHNAMEH);
                groundSymbol = P4Choise[SYMBOL];  // we use ground Symbol int just in this case
                baseSymbol[0] = P4Choise[SYMBOL]; // we use base Symbol array to build a global value and use it out of switchcase
                // second player
                drawPlayGround(0, ' ', 0, ' ', 0, ' ', P4Choise[NUMBER], intToSymbol(P4Choise[SYMBOL]), team1Score, team2Score);
                drawHandCards(P1cards, team1Wins, team2Wins);
                userReciever(P1cards, P1Choise, groundSymbol);
                // third player
                thirdCardFinder(P2cards, P2Choise, P4Choise, P1Choise, BAKHSHNAMEH, groundSymbol);
                // forth player
                forthCardFinder(P3cards, P3Choise, P4Choise, P1Choise, P2Choise, BAKHSHNAMEH, groundSymbol);
                break;
            }
            }
            // show result of round
            drawPlayGround(P1Choise[NUMBER], intToSymbol(P1Choise[SYMBOL]), P2Choise[NUMBER], intToSymbol(P2Choise[SYMBOL]), P3Choise[NUMBER], intToSymbol(P3Choise[SYMBOL]), P4Choise[NUMBER], intToSymbol(P4Choise[SYMBOL]), team1Score, team2Score);
            drawHandCards(P1cards, team1Wins, team2Wins);

            printf("Now enter something to see winner of round and update score table.\n");
            getch();
            // find winner of round and starter of next round
            int winner = winnerTeam(P1Choise[NUMBER], P1Choise[SYMBOL], P2Choise[NUMBER], P2Choise[SYMBOL],
                                    P3Choise[NUMBER], P3Choise[SYMBOL], P4Choise[NUMBER], P4Choise[SYMBOL], BAKHSHNAMEH, baseSymbol[0]);
            if (winner == 1)
            {
                printf("TEAM1 WINS!.\n");
                team1Score++;

                // find starter of next round
                starter = 1;
                if (moreValueable(P1Choise[NUMBER], P1Choise[SYMBOL], P3Choise[NUMBER], P3Choise[SYMBOL], BAKHSHNAMEH, baseSymbol[0]) == 2)
                {
                    starter = 3;
                }
            }
            else if (winner == 2)
            {
                printf("TEAM2 WINS!.\n");
                team2Score++;

                // find starter of next round
                starter = 2;
                if (moreValueable(P2Choise[NUMBER], P2Choise[SYMBOL], P4Choise[NUMBER], P4Choise[SYMBOL], BAKHSHNAMEH, baseSymbol[0]) == 2)
                {
                    starter = 4;
                }
            }

            if (team1Score > team2Score)
            {
                maxScore = team1Score;
            }
            else if (team1Score < team2Score)
            {
                maxScore = team2Score;
            }
            drawPlayGround(baseForm, '-', 0, '-', 0, '-', 0, '-', team1Score, team2Score);
            drawHandCards(P1cards, team1Wins, team2Wins);

            printf("Enter something to start next round\n");
            getch();
        }
        if (team1Score == MAXSCORE)
        {
            team1Wins++;
            printf("\n**** TEAM1 WINS THIS SET ****\nLet's play next set !\n");
            //  Advanced option
            // if team 1 wins all rounds, it recieves two setscores
            if (team2Score == 0)
            {
                team1Wins++;
            }
        }
        else
        {
            team2Wins++;
            printf("\n**** TEAM2 WINS THIS SET ****\nLet's play next set !\n");
            // Advanced option
            // if team 2 wins all rounds, it recieves two set scores
            if (team1Score == 0)
            {
                team2Wins++;
            }
        }

        //  Find winner of game
        if (set == MAXSET)
        {
            if (team1Wins > team2Wins)
            {
                printf("\n\nThe game is over! \n***** TEAM1 IS THE WINNER *****\n\n");
            }
            else
            {
                printf("\n\nThe game is over! \n***** TEAM2 IS THE WINNER *****\n\n");
            }
        }
        set++;
    }
    printf("Enter something to exit");
    getch();
    return 0;
}

void shuffle_card(int *card)
{
    int i, r, temp;
    for (temp = 0, i = 0; temp < 44; i++, temp++)
        card[temp] = i;
    srand(time(NULL));
    for (i = 43; i > 0; i--)
    {
        r = rand() % i;
        temp = card[i];
        card[i] = card[r];
        card[r] = temp;
    }
}
