#include "intToSymbol.h"

char intToSymbol(int symbolNum)
{
    char symbolChar;
    switch (symbolNum)
    {
    case 0:
        symbolChar = 'A';
        break;
    case 1:
        symbolChar = 'B';
        break;
    case 2:
        symbolChar = 'C';
        break;
    case 3:
        symbolChar = 'D';
        break;
    }
    return symbolChar;
}