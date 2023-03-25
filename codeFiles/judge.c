#include "judge.h"

int moreValueable(int firstChosenNum, int firstChosenSymbol, int secondChosenNum, int secondChosenSymbol, int bakhshName, int groundSymbol)
{
    // if they have same symbol, we compare their numbers
    if (firstChosenSymbol == secondChosenSymbol)
    {
        if (firstChosenNum > secondChosenNum)
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
    // if just one of them is bakhshnameh , it has more value
    else if (firstChosenSymbol == bakhshName)
    {
        return 1;
    }
    else if (secondChosenSymbol == bakhshName)
    {
        return 2;
    }
    // if there is no bakhshnameh and just one of them has ground symbol, it has more value
    else if (firstChosenSymbol == groundSymbol)
    {
        return 1;
    }
    else if (secondChosenSymbol == groundSymbol)
    {
        return 2;
    }
}
int winnerTeam(int P1ChosenNum, int P1ChosenSymbol, int P2ChosenNum, int P2ChosenSymbol,
               int P3ChosenNum, int P3ChosenSymbol, int P4ChosenNum, int P4ChosenSymbol, int bakhshName, int groundSymbol)
{
    int team1Best = moreValueable(P1ChosenNum, P1ChosenSymbol, P3ChosenNum, P3ChosenSymbol, bakhshName, groundSymbol);
    int team2Best = moreValueable(P2ChosenNum, P2ChosenSymbol, P4ChosenNum, P4ChosenSymbol, bakhshName, groundSymbol);
    int team1Num, team2Num, winnerNum;
    int team1Sym, team2Sym, winnerSym;
    if (team1Best == 1)
    {
        team1Num = P1ChosenNum;
        team1Sym = P1ChosenSymbol;
    }
    else
    {
        team1Num = P3ChosenNum;
        team1Sym = P3ChosenSymbol;
    }
    if (team2Best == 1)
    {
        team2Num = P2ChosenNum;
        team2Sym = P2ChosenSymbol;
    }
    else
    {
        team2Num = P4ChosenNum;
        team2Sym = P4ChosenSymbol;
    }
    return moreValueable(team1Num, team1Sym, team2Num, team2Sym, bakhshName, groundSymbol);
}
