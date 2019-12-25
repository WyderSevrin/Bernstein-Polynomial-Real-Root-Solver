
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

void initinvmdeg3(double a, double b, Matrice &invm)
{
    invm.setmat(1, 1, 0.0);
    invm.setmat(2, 1, 0.0);
    invm.setmat(3, 1, 0.0);
    invm.setmat(4, 1, 0.0);

    invm.setmat(1, 2, 0.0);
    invm.setmat(2, 2, 0.0);
    invm.setmat(3, 2, 0.0);
    invm.setmat(4, 2, 0.0);

    invm.setmat(1, 3, 0.0);
    invm.setmat(2, 3, 0.0);
    invm.setmat(3, 3, 0.0);
    invm.setmat(4, 3, 0.0);

    invm.setmat(1, 4, 0.0);
    invm.setmat(2, 4, 0.0);
    invm.setmat(3, 4, 0.0);
    invm.setmat(4, 4, 0.0);

    invm = invm * (1.0 / 2.0);
}

void initinvmdeg4(double a, double b, Matrice &invm)
{
    invm.setmat(1, 1, 0.0);
    invm.setmat(2, 1, 0.0);
    invm.setmat(3, 1, 0.0);
    invm.setmat(4, 1, 0.0);
    invm.setmat(5, 1, 0.0);

    invm.setmat(1, 2, 0.0);
    invm.setmat(2, 2, 0.0);
    invm.setmat(3, 2, 0.0);
    invm.setmat(4, 2, 0.0);
    invm.setmat(5, 2, 0.0);

    invm.setmat(1, 3, 0.0);
    invm.setmat(2, 3, 0.0);
    invm.setmat(3, 3, 0.0);
    invm.setmat(4, 3, 0.0);
    invm.setmat(5, 3, 0.0);

    invm.setmat(1, 4, 0.0);
    invm.setmat(2, 4, 0.0);
    invm.setmat(3, 4, 0.0);
    invm.setmat(4, 4, 0.0);
    invm.setmat(5, 4, 0.0);

    invm.setmat(1, 5, 0.0);
    invm.setmat(2, 5, 0.0);
    invm.setmat(3, 5, 0.0);
    invm.setmat(4, 5, 0.0);
    invm.setmat(5, 5, 0.0);

    invm = invm * (1.0 / 2.0);
}

void initinvmdeg5(double a, double b, Matrice &invm)
{
    invm.setmat(1, 1, 0.0);
    invm.setmat(2, 1, 0.0);
    invm.setmat(3, 1, 0.0);
    invm.setmat(4, 1, 0.0);
    invm.setmat(5, 1, 0.0);
    invm.setmat(6, 1, 0.0);

    invm.setmat(1, 2, 0.0);
    invm.setmat(2, 2, 0.0);
    invm.setmat(3, 2, 0.0);
    invm.setmat(4, 2, 0.0);
    invm.setmat(5, 2, 0.0);
    invm.setmat(6, 2, 0.0);

    invm.setmat(1, 3, 0.0);
    invm.setmat(2, 3, 0.0);
    invm.setmat(3, 3, 0.0);
    invm.setmat(4, 3, 0.0);
    invm.setmat(5, 3, 0.0);
    invm.setmat(6, 3, 0.0);

    invm.setmat(1, 4, 0.0);
    invm.setmat(2, 4, 0.0);
    invm.setmat(3, 4, 0.0);
    invm.setmat(4, 4, 0.0);
    invm.setmat(5, 4, 0.0);
    invm.setmat(6, 4, 0.0);

    invm.setmat(1, 5, 0.0);
    invm.setmat(2, 5, 0.0);
    invm.setmat(3, 5, 0.0);
    invm.setmat(4, 5, 0.0);
    invm.setmat(5, 5, 0.0);
    invm.setmat(6, 5, 0.0);

    invm.setmat(1, 6, 0.0);
    invm.setmat(2, 6, 0.0);
    invm.setmat(3, 6, 0.0);
    invm.setmat(4, 6, 0.0);
    invm.setmat(5, 6, 0.0);
    invm.setmat(6, 6, 0.0);

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

void initcastelGdeg3(Matrice &castelg)
{
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
}

void initcastelDdeg3(Matrice &casteld)
{
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
}

void initcastelGdeg4(Matrice &castelg)
{
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

    castelg.setmat(5, 1, 0.0625);       //     1/16
    castelg.setmat(5, 2, 0.0625 * 4.0); // 4/16
    castelg.setmat(5, 3, 0.0625 * 6.0); // 6/16 // pas forcément juste //triangle de pascal
    castelg.setmat(5, 4, 0.0625 * 4.0); // 4/16
    castelg.setmat(5, 5, 0.0625);       //    1/16
}

void initcastelDdeg4(Matrice &casteld)
{

    casteld.setmat(1, 1, 0.0625);       //     1/16
    casteld.setmat(1, 2, 0.0625 * 4.0); // 4/16
    casteld.setmat(1, 3, 0.0625 * 6.0); // 6/16 // pas forcément juste
    casteld.setmat(1, 4, 0.0625 * 4.0); // 4/16
    casteld.setmat(1, 5, 0.0625);       //    1/16

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
}

void initcastelGdeg5(Matrice &castelg)
{
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

    castelg.setmat(5, 1, 0.0625);       // 1/16
    castelg.setmat(5, 2, 0.0625 * 4.0); // 4/16
    castelg.setmat(5, 3, 0.0625 * 6.0); // 6/16 // pas forcément juste //triangle de pascal
    castelg.setmat(5, 4, 0.0625 * 4.0); // 4/16
    castelg.setmat(5, 5, 0.0625);       // 1/16
    castelg.setmat(5, 6, 0.0);

    castelg.setmat(6, 1, 0.03125);        // 1/32
    castelg.setmat(6, 2, 0.03125 * 5.0);  // 5/32
    castelg.setmat(6, 3, 0.03125 * 10.0); // 10/32  // pas forcément juste //triangle de pascal
    castelg.setmat(6, 4, 0.03125 * 10.0); // 10/32
    castelg.setmat(6, 5, 0.03125 * 5.0);  // 5/32
    castelg.setmat(6, 6, 0.03125);        // 1/32
}

void initcastelDdeg5(Matrice &casteld)
{

    casteld.setmat(1, 1, 0.03125);        // 1/32
    casteld.setmat(1, 2, 0.03125 * 5.0);  // 5/32
    casteld.setmat(1, 3, 0.03125 * 10.0); // 10/32  // pas forcément juste //triangle de pascal
    casteld.setmat(1, 4, 0.03125 * 10.0); // 10/32
    casteld.setmat(1, 5, 0.03125 * 5.0);  // 5/32
    casteld.setmat(1, 6, 0.03125);        // 1/32

    casteld.setmat(2, 1, 0.0);
    casteld.setmat(2, 2, 0.0625);       // 1/16
    casteld.setmat(2, 3, 0.0625 * 4.0); // 4/16
    casteld.setmat(2, 4, 0.0625 * 6.0); // 6/16 // pas forcément juste //triangle de pascal
    casteld.setmat(2, 5, 0.0625 * 4.0); // 4/16
    casteld.setmat(2, 6, 0.0625);       // 1/16

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
}