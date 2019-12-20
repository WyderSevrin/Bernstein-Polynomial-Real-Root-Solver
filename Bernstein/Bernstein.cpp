#include "Bernstein.h"

void rootfinder(double precision) {} //recurence!!//quick sort algo

Bernstein::Bernstein(double a, double b, double c, double d, double e, double f) //deg 5
{
}
Bernstein::Bernstein(double a, double b, double c, double d, double e) //deg 4
{
}
Bernstein::Bernstein(double a, double b, double c, double d) //deg 3
{
}
Bernstein::Bernstein(double a, double b, double c) //deg 2
{
    m_coeff = Matrice(3, 1);
    m_coeff.setmat(1, 1, c);
    m_coeff.setmat(2, 1, b);
    m_coeff.setmat(3, 1, a);
    double intervalA = -1.0 * maxinterval(m_coeff); // a metre dans une classe
    double intervalB = maxinterval(m_coeff);
    m_invm = Matrice(3, 3);
    initinvmdeg2(intervalA, intervalB, m_invm);
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
    invm.setmat(3, 3, 0.0 * b * b);

    invm *(1.0 / 2.0);
}

