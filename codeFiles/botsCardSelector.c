#include <stdlib.h>
#include "botsCardSelector.h"
#include "maxAndMin.h"
#include "judge.h"

// define booleans
#define False 0
#define True 1
// guid for some Arrays indexes and base version of functions
#define NUMBER 0
#define SYMBOL 1
#define baseForm -1

int firstCardFinder(int cards[4][11], int chosen[], int bakhshnaneh)
{
    int cardSym, min = 11;
    for (int symbol = 0; symbol < 4; symbol++)
    {
        if (cards[symbol][10])
        {
            chosen[SYMBOL] = symbol;
            chosen[NUMBER] = 11;
            cards[chosen[SYMBOL]][chosen[NUMBER] - 1] = 0;
            return 0;
        }
    }
    for (int symbol = 0; symbol < 4; symbol++)
    {
        if (cards[symbol][9])
        {
            chosen[SYMBOL] = symbol;
            chosen[NUMBER] = 10;
            cards[chosen[SYMBOL]][chosen[NUMBER] - 1] = 0;
            return 0;
        }
    }
    // if player hasn't any highNumber card
    for (int symbol = 0; symbol < 4; symbol++)
    {
        for (int cardNum = 0; cardNum < 11; cardNum++)
        {
            if (cards[symbol][cardNum] && cards[symbol][cardNum] < chosen[NUMBER] && symbol != bakhshnaneh)
            {
                chosen[SYMBOL] = symbol;
                chosen[NUMBER] = cards[symbol][cardNum];
            }
        }
    }
    cards[chosen[SYMBOL]][chosen[NUMBER] - 1] = 0;
}
int secondCardFinder(int cards[4][11], int chosen[], int firstCard[], int bakhshnaneh, int groundSymbol)
{
    int haveSame = False;
    for (int i = 0; i < 11; i++)
    {
        if (cards[firstCard[SYMBOL]][i])
        {
            haveSame = True;
            chosen[SYMBOL] = firstCard[SYMBOL];
            chosen[NUMBER] = maxNum(cards, chosen[SYMBOL]);
            break;
        }
    }
    if (haveSame == False)
    {
        // search for Bakhshname symbol in second Player Cards
        int haveBakhshname = False;
        for (int i = 0; i < 11; i++)
        {
            if (cards[bakhshnaneh][i])
            {
                haveBakhshname = True;
                chosen[SYMBOL] = bakhshnaneh;
                chosen[NUMBER] = maxNum(cards, chosen[SYMBOL]);
                break;
            }
        }
        if (haveBakhshname == False)
        {
            chosen[NUMBER] = minAllNums(cards);
            chosen[SYMBOL] = minAllNumsSymbol(cards);
        }
    }
    cards[chosen[SYMBOL]][chosen[NUMBER] - 1] = 0;
    return 0;
}
int thirdCardFinder(int cards[4][11], int chosen[], int firstCard[], int secondCard[], int bakhshnaneh, int groundSymbol)
{
    int moreValueablePlayer = moreValueable(firstCard[NUMBER], firstCard[SYMBOL], secondCard[NUMBER], secondCard[SYMBOL], bakhshnaneh, groundSymbol);
    // if card of third player's teammate(first player) is less valueable than second player's card
    if (moreValueablePlayer == 2)
    {
        // search for background symbol in third player cards
        int haveSame = False;
        for (int i = 0; i < 11; i++)
        {
            if (cards[firstCard[SYMBOL]][i])
            {
                haveSame = True;
                chosen[SYMBOL] = firstCard[SYMBOL];
                chosen[NUMBER] = maxNum(cards, chosen[SYMBOL]);
                break;
            }
        }

        if (haveSame == False)
        {
            // search for Bakhshname symbol in P3cards
            int haveBakhshname = False;
            for (int i = 0; i < 11; i++)
            {
                if (cards[bakhshnaneh][i])
                {
                    haveBakhshname = True;
                    chosen[SYMBOL] = bakhshnaneh;
                    chosen[NUMBER] = maxNum(cards, bakhshnaneh);
                    break;
                }
            }
            if (haveBakhshname == False)
            {
                chosen[SYMBOL] = minAllNumsSymbol(cards);
                chosen[NUMBER] = minAllNums(cards);
            }
        }
    }
    // ** Advanced section **
    // if card of third player's teammate(first player) is more valueable than second player's card
    else if (moreValueablePlayer == 1)
    {
        // search for same symbol in third player cards
        int haveSame = False;
        for (int i = 0; i < 11; i++)
        {
            if (cards[firstCard[SYMBOL]][i])
            {
                haveSame = True;
                chosen[SYMBOL] = firstCard[SYMBOL];
                chosen[NUMBER] = minNum(cards, chosen[SYMBOL]);
                break;
            }
        }

        if (haveSame == False)
        {
            // search for non-Bakhshname symbol in third player cards
            int haveNonBakhshname = False, min = 11;
            for (int symbol = 0; symbol < 4; symbol++)
            {
                for (int i = 0; i < 11; i++)
                {
                    // if symbol isn't bakhshname and some cards are available and less than min, change the min number and symbol
                    if (symbol != bakhshnaneh && cards[symbol][i] && cards[symbol][i] < min)
                    {
                        haveNonBakhshname = True;
                        min = cards[symbol][i];
                        chosen[SYMBOL] = symbol;
                        chosen[NUMBER] = min;
                    }
                }
            }
            if (haveNonBakhshname == False)
            {
                chosen[SYMBOL] = bakhshnaneh;
                chosen[NUMBER] = minNum(cards, bakhshnaneh);
            }
        }
    }
    cards[chosen[SYMBOL]][chosen[NUMBER] - 1] = 0;
    return 0;
}
int forthCardFinder(int cards[4][11], int chosen[], int firstCard[], int secondCard[], int thirdCard[], int bakhshnaneh, int groundSymbol)
{
    int moreValueablePlayer21 = moreValueable(secondCard[NUMBER], secondCard[SYMBOL], firstCard[NUMBER], firstCard[SYMBOL], bakhshnaneh, groundSymbol);
    int moreValueablePlayer23 = moreValueable(secondCard[NUMBER], secondCard[SYMBOL], thirdCard[NUMBER], thirdCard[SYMBOL], bakhshnaneh, groundSymbol);
    // if card of forth player's teammate(second player) is less valueable than first or third player card
    if (moreValueablePlayer21 == 2 || moreValueablePlayer23 == 2)
    {
        // search for same symbol in forth player cards
        int haveSame = False;
        for (int i = 0; i < 11; i++)
        {
            if (cards[firstCard[SYMBOL]][i])
            {
                haveSame = True;
                chosen[SYMBOL] = firstCard[SYMBOL];
                chosen[NUMBER] = maxNum(cards, chosen[SYMBOL]);
                break;
            }
        }
        if (haveSame == False)
        {
            // search for Bakhshname symbol in P4cards
            int haveBakhshname = False;
            for (int i = 0; i < 11; i++)
            {
                if (cards[bakhshnaneh][i])
                {
                    haveBakhshname = True;
                    chosen[SYMBOL] = bakhshnaneh;
                    chosen[NUMBER] = maxNum(cards, bakhshnaneh);
                    break;
                }
            }
            if (haveBakhshname == False)
            {
                chosen[SYMBOL] = minAllNumsSymbol(cards);
                chosen[NUMBER] = minAllNums(cards);
            }
        }
    }
    // ** Advanced section **
    // if card of forth player's teammate(second player) is more valueable than first and third player's card
    else if (moreValueablePlayer21 == 1 && moreValueablePlayer23 == 1)
    {
        // search for same symbol in forth player cards
        int haveSame = False;
        for (int i = 0; i < 11; i++)
        {
            if (cards[firstCard[SYMBOL]][i])
            {
                haveSame = True;
                chosen[SYMBOL] = firstCard[SYMBOL];
                chosen[NUMBER] = minNum(cards, chosen[SYMBOL]);
                break;
            }
        }
        if (haveSame == False)
        {
            // search for non-Bakhshname symbol in forth player cards
            int haveNonBakhshname = False, min = 11;
            for (int symbol = 0; symbol < 4; symbol++)
            {
                for (int i = 0; i < 11; i++)
                {
                    // if symbol isn't bakhshname and some cards are available and less than min, change the min number and symbol
                    if (symbol != bakhshnaneh && cards[symbol][i] && cards[symbol][i] < min)
                    {
                        haveNonBakhshname = True;
                        min = cards[symbol][i];
                        chosen[SYMBOL] = symbol;
                        chosen[NUMBER] = min;
                    }
                }
            }
            if (haveNonBakhshname == False)
            {
                chosen[SYMBOL] = bakhshnaneh;
                chosen[NUMBER] = minNum(cards, bakhshnaneh);
            }
        }
    }
    cards[chosen[SYMBOL]][chosen[NUMBER] - 1] = 0;
    return 0;
}
