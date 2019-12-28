
#include "Fonction.h"

double maxinterval(Matrice &coeff) //renvoie le coefficient la valeur la plus grande +1 , dans une matrice (m,1) qui servira a faire un interval
{                                  // 1+coeffmax
    double max = absolue(coeff.getcell(0, 0));
    for (int i = 0; i < coeff.getligne(); i++)
    {
        if (max < absolue(coeff.getcell(i, 0)))
        {
            max = absolue(coeff.getcell(i, 0));
        }
    }
    return absolue(max) + 1.0;
}

double absolue(double a) //renvoie la valeur absolue
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

Matrice initmdeg2(double a, double b) //renvoie la matrice de M d'interval [a,b]
{
    Matrice m(3, 3);
    m.setmat(1, 1, b * b);
    m.setmat(1, 2, -2.0 * b * a);
    m.setmat(1, 3, a * a);

    m.setmat(2, 1, -2.0 * b);
    m.setmat(2, 2, 2.0 * (a + b));
    m.setmat(2, 3, -2.0 * a);

    m.setmat(3, 1, 1.0);
    m.setmat(3, 2, -2.0);
    m.setmat(3, 3, 1.00);

    m = m * (1.0 / ((b - a) * (b - a)));
    return m;
}

Matrice initmdeg3(double a, double b) //renvoie la matrice de M d'interval [a,b]
{
    Matrice m(4, 4);
    m.setmat(1, 1, b * b * b);
    m.setmat(2, 1, -3.0 * b * b);
    m.setmat(3, 1, 3.0 * b);
    m.setmat(4, 1, -1.0);

    m.setmat(1, 2, -3.0 * b * b * a);
    m.setmat(2, 2, 3.0 * b * b + 6.0 * b * a);
    m.setmat(3, 2, -6.0 * b - 3.0 * a);
    m.setmat(4, 2, 3.0);

    m.setmat(1, 3, 3.0 * a * a * b);
    m.setmat(2, 3, -3.0 * a * a - 6.0 * b * a);
    m.setmat(3, 3, 3.0 * b + 6.0 * a);
    m.setmat(4, 3, -3.0);

    m.setmat(1, 4, -a * a * a);
    m.setmat(2, 4, 3.0 * a * a);
    m.setmat(3, 4, -3.0 * a);
    m.setmat(4, 4, 1.0);

    m = m * (1.0 / ((b - a) * (b - a) * (b - a)));
    return m;
}

Matrice initmdeg4(double a, double b) //renvoie la matrice de M d'interval [a,b]
{
    Matrice m(5, 5);
    m.setmat(1, 1, b * b * b * b);
    m.setmat(2, 1, -4.0 * b * b * b);
    m.setmat(3, 1, 6.0 * b * b);
    m.setmat(4, 1, -4.0 * b);
    m.setmat(5, 1, 1.0);

    m.setmat(1, 2, -4.0 * a * b * b * b);
    m.setmat(2, 2, 4.0 * b * b * b + 12.0 * a * b * b);
    m.setmat(3, 2, -12.0 * b * b - 12.0 * a * b);
    m.setmat(4, 2, 4.0 * a + 12 * b);
    m.setmat(5, 2, -4.0);

    m.setmat(1, 3, 6.0 * a * a * b * b);
    m.setmat(2, 3, -12.0 * a * b * b - 12.0 * a * a * b);
    m.setmat(3, 3, 6.0 * a * a + 6 * b * b + 12.0 * a * b);
    m.setmat(4, 3, -12.0 * a - 12.0 * b);
    m.setmat(5, 3, 6.0);

    m.setmat(1, 4, -4.0 * a * a * a * b);
    m.setmat(2, 4, 4.0 * a * a * a + 12.0 * a * a * b);
    m.setmat(3, 4, -12.0 * a * a - 12.0 * a * b);
    m.setmat(4, 4, 12.0 * a + 4.0 * b);
    m.setmat(5, 4, -4.0);

    m.setmat(1, 5, a * a * a * a);
    m.setmat(2, 5, -4.0 * a * a * a);
    m.setmat(3, 5, 6.0 * a * a);
    m.setmat(4, 5, -4.0 * a);
    m.setmat(5, 5, 1.0);

    m = m * (1.0 / ((b - a) * (b - a) * (b - a) * (b - a)));

    return m;
}

Matrice initmdeg5(double a, double b) //renvoie la matrice de M d'interval [a,b]
{
    Matrice m(6, 6);
    m.setmat(1, 1, b * b * b * b * b);
    m.setmat(2, 1, -5.0 * b * b * b * b);
    m.setmat(3, 1, 10.0 * b * b * b);
    m.setmat(4, 1, -10.0 * b * b);
    m.setmat(5, 1, 5.0 * b);
    m.setmat(6, 1, -1.0);

    m.setmat(1, 2, -5.0 * a * b * b * b * b);
    m.setmat(2, 2, 20.0 * a * b * b * b + 5.0 * b * b * b * b);
    m.setmat(3, 2, -30.0 * a * b * b - 20.0 * b * b * b);
    m.setmat(4, 2, 20.0 * a * b + 30.0 * b * b);
    m.setmat(5, 2, -20.0 * b - 5.0 * a);
    m.setmat(6, 2, 5.0);

    m.setmat(1, 3, 10.0 * a * a * b * b * b);
    m.setmat(2, 3, -30.0 * a * a * b * b - 20 * a * b * b * b);
    m.setmat(3, 3, 30.0 * a * a * b + 60 * a * b * b + 10.0 * b * b * b);
    m.setmat(4, 3, -10.0 * a * a - 60.0 * a * b - 30.0 * b * b);
    m.setmat(5, 3, 20.0 * a + 30.0 * b);
    m.setmat(6, 3, -10.0);

    m.setmat(1, 4, -10.0 * a * a * a * b * b);
    m.setmat(2, 4, 20.0 * a * a * a * b + 30.0 * a * a * b * b);
    m.setmat(3, 4, -10.0 * a * a * a - 60.0 * a * a * b - 30.0 * a * b * b);
    m.setmat(4, 4, 30.0 * a * a + 60 * a * b + 10.0 * b * b);
    m.setmat(5, 4, -30.0 * a - 20.0 * b);
    m.setmat(6, 4, 10.0);

    m.setmat(1, 5, 5.0 * a * a * a * a * b);
    m.setmat(2, 5, -5.0 * a * a * a * a - 20.0 * a * a * a * b);
    m.setmat(3, 5, 20.0 * a * a * a + 30.0 * a * a * b);
    m.setmat(4, 5, -30.0 * a * a - 20.0 * a * b);
    m.setmat(5, 5, 20.0 * a + 5.0 * b);
    m.setmat(6, 5, -5.0);

    m.setmat(1, 6, -1.0 * a * a * a * a * a);
    m.setmat(2, 6, 5.0 * a * a * a * a);
    m.setmat(3, 6, -10.0 * a * a * a);
    m.setmat(4, 6, 10.0 * a * a);
    m.setmat(5, 6, -5.0 * a);
    m.setmat(6, 6, 1.0);

    m = m * (1.0 / ((b - a) * (b - a) * (b - a) * (b - a) * (b - a)));

    return m;
}

Matrice initcastelGdeg2() //renvoie la matrice de casteljau
{

    Matrice castelg(3, 3);
    castelg.setmat(1, 1, 1.0);
    castelg.setmat(1, 2, 0.0);
    castelg.setmat(1, 3, 0.0);

    castelg.setmat(2, 1, 0.5);
    castelg.setmat(2, 2, 0.5);
    castelg.setmat(2, 3, 0.0);

    castelg.setmat(3, 1, 0.25);
    castelg.setmat(3, 2, 0.5);
    castelg.setmat(3, 3, 0.25);
    return castelg;
}

Matrice initcastelDdeg2() //renvoie la matrice de casteljau
{
    Matrice casteld(3, 3);
    casteld.setmat(1, 1, 0.25);
    casteld.setmat(1, 2, 0.5);
    casteld.setmat(1, 3, 0.25);

    casteld.setmat(2, 1, 0.0);
    casteld.setmat(2, 2, 0.5);
    casteld.setmat(2, 3, 0.5);

    casteld.setmat(3, 1, 0.0);
    casteld.setmat(3, 2, 0.0);
    casteld.setmat(3, 3, 1.0);
    return casteld;
}

Matrice initcastelGdeg3() //renvoie la matrice de casteljau
{
    Matrice castelg(4, 4);
    castelg.setmat(1, 1, 1.0);
    castelg.setmat(1, 2, 0.0);
    castelg.setmat(1, 3, 0.0);
    castelg.setmat(1, 4, 0.0);

    castelg.setmat(2, 1, 0.5);
    castelg.setmat(2, 2, 0.5);
    castelg.setmat(2, 3, 0.0);
    castelg.setmat(2, 4, 0.0);

    castelg.setmat(3, 1, 0.25);
    castelg.setmat(3, 2, 0.5);
    castelg.setmat(3, 3, 0.25);
    castelg.setmat(3, 4, 0.0);

    castelg.setmat(4, 1, 0.125);
    castelg.setmat(4, 2, 0.125 * 3.0);
    castelg.setmat(4, 3, 0.125 * 3.0);
    castelg.setmat(4, 4, 0.125);
    return castelg;
}

Matrice initcastelDdeg3() //renvoie la matrice de casteljau
{
    Matrice casteld(4, 4);
    casteld.setmat(1, 1, 0.125);
    casteld.setmat(1, 2, 0.125 * 3.0);
    casteld.setmat(1, 3, 0.125 * 3.0);
    casteld.setmat(1, 4, 0.125);

    casteld.setmat(2, 1, 0.0);
    casteld.setmat(2, 2, 0.25);
    casteld.setmat(2, 3, 0.5);
    casteld.setmat(2, 4, 0.25);

    casteld.setmat(3, 1, 0.0);
    casteld.setmat(3, 2, 0.0);
    casteld.setmat(3, 3, 0.5);
    casteld.setmat(3, 4, 0.5);

    casteld.setmat(4, 1, 0.0);
    casteld.setmat(4, 2, 0.0);
    casteld.setmat(4, 3, 0.0);
    casteld.setmat(4, 4, 1.0);
    return casteld;
}

Matrice initcastelGdeg4() //renvoie la matrice de casteljau
{
    Matrice castelg(5, 5);
    castelg.setmat(1, 1, 1.0);
    castelg.setmat(1, 2, 0.0);
    castelg.setmat(1, 3, 0.0);
    castelg.setmat(1, 4, 0.0);
    castelg.setmat(1, 5, 0.0);

    castelg.setmat(2, 1, 0.5);
    castelg.setmat(2, 2, 0.5);
    castelg.setmat(2, 3, 0.0);
    castelg.setmat(2, 4, 0.0);
    castelg.setmat(2, 5, 0.0);

    castelg.setmat(3, 1, 0.25);
    castelg.setmat(3, 2, 0.25 * 2);
    castelg.setmat(3, 3, 0.25);
    castelg.setmat(3, 4, 0.0);
    castelg.setmat(3, 5, 0.0);

    castelg.setmat(4, 1, 0.125);
    castelg.setmat(4, 2, 0.125 * 3.0);
    castelg.setmat(4, 3, 0.125 * 3.0);
    castelg.setmat(4, 4, 0.125);
    castelg.setmat(4, 5, 0.0);

    castelg.setmat(5, 1, 0.0625);
    castelg.setmat(5, 2, 0.0625 * 4.0);
    castelg.setmat(5, 3, 0.0625 * 6.0);
    castelg.setmat(5, 4, 0.0625 * 4.0);
    castelg.setmat(5, 5, 0.0625);

    return castelg;
}

Matrice initcastelDdeg4() //renvoie la matrice de casteljau
{
    Matrice casteld(5, 5);
    casteld.setmat(1, 1, 0.0625);
    casteld.setmat(1, 2, 0.0625 * 4.0);
    casteld.setmat(1, 3, 0.0625 * 6.0);
    casteld.setmat(1, 4, 0.0625 * 4.0);
    casteld.setmat(1, 5, 0.0625);

    casteld.setmat(2, 1, 0.0);
    casteld.setmat(2, 2, 0.125);
    casteld.setmat(2, 3, 0.125 * 3.0);
    casteld.setmat(2, 4, 0.125 * 3.0);
    casteld.setmat(2, 5, 0.125);

    casteld.setmat(3, 1, 0.0);
    casteld.setmat(3, 2, 0.0);
    casteld.setmat(3, 3, 0.25);
    casteld.setmat(3, 4, 0.25 * 2.0);
    casteld.setmat(3, 5, 0.25);

    casteld.setmat(4, 1, 0.0);
    casteld.setmat(4, 2, 0.0);
    casteld.setmat(4, 3, 0.0);
    casteld.setmat(4, 4, 0.5);
    casteld.setmat(4, 5, 0.5);

    casteld.setmat(5, 1, 0.0);
    casteld.setmat(5, 2, 0.0);
    casteld.setmat(5, 3, 0.0);
    casteld.setmat(5, 4, 0.0);
    casteld.setmat(5, 5, 1.0);
    return casteld;
}

Matrice initcastelGdeg5() //renvoie la matrice de casteljau
{
    Matrice castelg(6, 6);
    castelg.setmat(1, 1, 1.0);
    castelg.setmat(1, 2, 0.0);
    castelg.setmat(1, 3, 0.0);
    castelg.setmat(1, 4, 0.0);
    castelg.setmat(1, 5, 0.0);
    castelg.setmat(1, 6, 0.0);

    castelg.setmat(2, 1, 0.5);
    castelg.setmat(2, 2, 0.5);
    castelg.setmat(2, 3, 0.0);
    castelg.setmat(2, 4, 0.0);
    castelg.setmat(2, 5, 0.0);
    castelg.setmat(2, 6, 0.0);

    castelg.setmat(3, 1, 0.25);
    castelg.setmat(3, 2, 0.25 * 2);
    castelg.setmat(3, 3, 0.25);
    castelg.setmat(3, 4, 0.0);
    castelg.setmat(3, 5, 0.0);
    castelg.setmat(3, 6, 0.0);

    castelg.setmat(4, 1, 0.125);
    castelg.setmat(4, 2, 0.125 * 3.0);
    castelg.setmat(4, 3, 0.125 * 3.0);
    castelg.setmat(4, 4, 0.125);
    castelg.setmat(4, 5, 0.0);
    castelg.setmat(4, 6, 0.0);

    castelg.setmat(5, 1, 0.0625);
    castelg.setmat(5, 2, 0.0625 * 4.0);
    castelg.setmat(5, 3, 0.0625 * 6.0);
    castelg.setmat(5, 4, 0.0625 * 4.0);
    castelg.setmat(5, 5, 0.0625);
    castelg.setmat(5, 6, 0.0);

    castelg.setmat(6, 1, 0.03125);
    castelg.setmat(6, 2, 0.03125 * 5.0);
    castelg.setmat(6, 3, 0.03125 * 10.0);
    castelg.setmat(6, 4, 0.03125 * 10.0);
    castelg.setmat(6, 5, 0.03125 * 5.0);
    castelg.setmat(6, 6, 0.03125);

    return castelg;
}

Matrice initcastelDdeg5() //renvoie la matrice de casteljau
{
    Matrice casteld(6, 6);
    casteld.setmat(1, 1, 0.03125);
    casteld.setmat(1, 2, 0.03125 * 5.0);
    casteld.setmat(1, 3, 0.03125 * 10.0);
    casteld.setmat(1, 4, 0.03125 * 10.0);
    casteld.setmat(1, 5, 0.03125 * 5.0);
    casteld.setmat(1, 6, 0.03125);

    casteld.setmat(2, 1, 0.0);
    casteld.setmat(2, 2, 0.0625);
    casteld.setmat(2, 3, 0.0625 * 4.0);
    casteld.setmat(2, 4, 0.0625 * 6.0);
    casteld.setmat(2, 5, 0.0625 * 4.0);
    casteld.setmat(2, 6, 0.0625);

    casteld.setmat(3, 1, 0.0);
    casteld.setmat(3, 2, 0.0);
    casteld.setmat(3, 3, 0.125);
    casteld.setmat(3, 4, 0.125 * 3.0);
    casteld.setmat(3, 5, 0.125 * 3.0);
    casteld.setmat(3, 6, 0.125);

    casteld.setmat(4, 1, 0.0);
    casteld.setmat(4, 2, 0.0);
    casteld.setmat(4, 3, 0.0);
    casteld.setmat(4, 4, 0.25);
    casteld.setmat(4, 5, 0.25 * 2);
    casteld.setmat(4, 6, 0.25);

    casteld.setmat(5, 1, 0.0);
    casteld.setmat(5, 2, 0.0);
    casteld.setmat(5, 3, 0.0);
    casteld.setmat(5, 4, 0.0);
    casteld.setmat(5, 5, 0.5);
    casteld.setmat(5, 6, 0.5);

    casteld.setmat(6, 1, 0.0);
    casteld.setmat(6, 2, 0.0);
    casteld.setmat(6, 3, 0.0);
    casteld.setmat(6, 4, 0.0);
    casteld.setmat(6, 5, 0.0);
    casteld.setmat(6, 6, 1.0);
    return casteld;
}