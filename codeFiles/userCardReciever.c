#include <stdio.h>
#include "userCardReciever.h"
#include "intToSymbol.h"
#include <conio.h>

// define booleans
#define False 0
#define True 1
// guid for some Arrays indexes and base version of functions
#define NUMBER 0
#define SYMBOL 1
#define baseForm -1

void userReciever(int cards[4][11], int chosen[], int groundSymbol)
{
    // recieve and check validity of input index
    int cardIndex = baseForm;
    printf("Which card do you want to play?\n");
    scanf("%d", &cardIndex);
    getchar();
    int isIndexValid = False, hasBackground = False;
    while (isIndexValid == False)
    {
        // check that user input a number between 0 to 10
        if (cardIndex == 0 || cardIndex == 1 || cardIndex == 2 || cardIndex == 3 || cardIndex == 4 || cardIndex == 5 || cardIndex == 6 || cardIndex == 7 || cardIndex == 8 || cardIndex == 9 || cardIndex == 10)
        {
            // find symbol and number of chosen card and check its validity
            int index = 0;
            for (int symbol = 0; symbol < 4; symbol++)
            {
                for (int cardNum = 0; cardNum < 11; cardNum++)
                {
                    if (cards[symbol][cardNum])
                    {
                        // If the index is available and doesnt'n used before
                        if (index == cardIndex && cards[symbol][cardNum] != -1)
                        {
                            // check if user has background symbol or not
                            for (int cardNum = 0; cardNum < 11; cardNum++)
                            {
                                // If the number is available and doesnt'n used before
                                if (cards[groundSymbol][cardNum] && cards[groundSymbol][cardNum] != -1)
                                {
                                    hasBackground = True;
                                }
                            }
                            // If user is  starter of round, or he hasn't backgroundcard or its card's symbol is the ground symbol, its valid
                            if (groundSymbol == baseForm || hasBackground == False || symbol == groundSymbol)
                            {
                                isIndexValid = True;
                                chosen[SYMBOL] = symbol;
                                chosen[NUMBER] = cardNum + 1;
                                cards[symbol][cardNum] = -1;
                            }
                        }
                        index++;
                    }
                }
            }
        }

        if (isIndexValid == False)
        {
            printf("You chose invalid index or this card used before or its symbol isn't the ground symbol.\nchoose again :\n");
            scanf("%d", &cardIndex);
            getchar();
        }
    }
    printf("You chose %c%d\n", intToSymbol(chosen[SYMBOL]), chosen[NUMBER]);
    printf("Now enter something to see all cards and update your hand cards.\n");
    getch();
}
