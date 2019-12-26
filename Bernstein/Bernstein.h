#ifndef BERNSTEIN_H
#define BERNSTEIN_H

#include "Matrice.h"
#include "Fonction.h"
#include "Interval.h"

class Bernstein
{
private:
    int m_iteration;
    int m_maxiteration;
    Matrice m_invmG;
    Matrice m_invmD;
    Matrice m_castelG;
    Matrice m_castelD;
    Matrice m_coeff;
    std::vector<double> m_racine;
    Interval m_origin;
    Interval m_originG;
    Interval m_originD;
    void rootfinder(Matrice controlpoint, Interval interval, double precision); //recurence!!//quick sort algo

public:
    void root(double precision);
    void showracine();
    void setmaxiteration(int i);

    Bernstein(double a, double b, double c, double d, double e, double f); //deg 5
    Bernstein(double a, double b, double c, double d, double e);           //deg 4
    Bernstein(double a, double b, double c, double d);                     //deg 3
    Bernstein(double a, double b, double c);                               //deg 2
};

#endif