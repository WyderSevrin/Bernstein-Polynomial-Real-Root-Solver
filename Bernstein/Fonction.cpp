
#include "Fonction.h"

double maxinterval(Matrice &coeff)
{ // 1+coeffmax
    double max = absolue(coeff.getcell(0, 0));
    for (int i = 0; i < coeff.getline(); i++)
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

void initinvmdeg2(double a, double b, Matrice &invm)
{
    invm.setmat(1, 1, 2.0);
    invm.setmat(2, 1, 2.0);
    invm.setmat(3, 1, 2.0);

    invm.setmat(1, 2, 2.0 * a);
    invm.setmat(2, 2, a + b);
    invm.setmat(3, 2, 2.0 * b);

    invm.setmat(1, 3, 2.0 * a * a);
    invm.setmat(2, 3, 2.0 * a * b);
    invm.setmat(3, 3, 2.0 * b * b);

    invm = invm * (1.0 / 2.0);
}

void initcastelGdeg2(Matrice &castelg)
{
    castelg.setmat(1, 1, 1.0);
    castelg.setmat(1, 2, 0.0);
    castelg.setmat(1, 3, 0.0);

    castelg.setmat(2, 1, 0.5);
    castelg.setmat(2, 2, 0.5);
    castelg.setmat(2, 3, 0.0);

    castelg.setmat(3, 1, 0.25);
    castelg.setmat(3, 2, 0.5);
    castelg.setmat(3, 3, 0.25);
}

void initcastelDdeg2(Matrice &casteld)
{
    casteld.setmat(1, 1, 0.25);
    casteld.setmat(1, 2, 0.5);
    casteld.setmat(1, 3, 0.25);

    casteld.setmat(2, 1, 0.0);
    casteld.setmat(2, 2, 0.5);
    casteld.setmat(2, 3, 0.5);

    casteld.setmat(3, 1, 0.0);
    casteld.setmat(3, 2, 0.0);
    casteld.setmat(3, 3, 1.0);
}