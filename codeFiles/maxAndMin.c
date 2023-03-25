#include "maxAndMin.h"

int maxNum(int playerCards[4][11], int symbol)
{
    int max = 1;
    for (int i = 0; i < 11; i++)
    {
        if (playerCards[symbol][i] > max)
        {
            max = playerCards[symbol][i];
        }
    }
    return max;
}
int minNum(int playerCards[4][11], int symbol)
{
    int min = 11;
    for (int i = 0; i < 11; i++)
    {
        if (playerCards[symbol][i] && playerCards[symbol][i] < min)
        {
            min = playerCards[symbol][i];
        }
    }
    return min;
}
int minAllNums(int playerCards[4][11])
{
    int min = 11;
    for (int symbol = 0; symbol < 4; symbol++)
    {
        for (int i = 0; i < 11; i++)
        {
            // if player card is non-zero and its less than min
            if (playerCards[symbol][i] && playerCards[symbol][i] < min)
            {
                min = playerCards[symbol][i];
            }
        }
    }
    return min;
}
int minAllNumsSymbol(int playerCards[4][11])
{
    int min = 11, minNumSymbol;
    for (int symbol = 0; symbol < 4; symbol++)
    {
        for (int i = 0; i < 11; i++)
        {
            // if player card is non-zero and its less than min
            if (playerCards[symbol][i] && playerCards[symbol][i] < min)
            {
                min = playerCards[symbol][i];
                minNumSymbol = symbol;
            }
        }
    }
    return minNumSymbol;
}
