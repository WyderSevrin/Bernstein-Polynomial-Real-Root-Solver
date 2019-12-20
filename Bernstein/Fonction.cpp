
#include "Fonction.h"

double maxinterval(Matrice &coeff)
{ // 1+coeffmax
    double max = absolue(coeff.getcell(0, 0));
    for (int i = 0; i < coeff.getline; i++)
    {
        if (max < absolue(coeff.getcell(i, 0)))
        {
            max = absolue(coeff.getcell(i, 0));
        }
    }
    return absolue(max) + 1.0;
}

double absolue(double a)
{
    if (a < 0)
    {
        return a * (-1.0);
    }
    else
    {
        return a;
    }
}