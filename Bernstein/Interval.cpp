#include "Interval.h"

double Interval::getgauche() const
{
    return m_gauche;
}
double Interval::getdroite() const
{

    return m_droite;
}
double Interval::getdelta() const
{

    return m_delta;
}

void Interval::setgauche(double g)
{
    m_gauche = g;
}
void Interval::setdroite(double d)
{
    m_droite = d;
}

Interval Interval::castelgauche()
{
    return Interval(m_gauche, m_droite / 2.0);
}
Interval Interval::castetdroite()
{
    return Interval(m_gauche / 2.0, m_droite);
}

Interval::Interval(double g, double d)
{
    m_gauche = g;
    m_droite = d;
    m_delta = d - g;
}