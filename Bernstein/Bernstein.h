#ifndef BERNSTEIN_H
#define BERNSTEIN_H

#include "Matrice.h"

class Bernstein
{
private:
    Matrice m_invm;
    Matrice m_castelG;
    Matrice m_castelD;
    Matrice m_coeff;
    std::vector<double> racine;

public:
    void rootfinder(double precision); //recurence!!//quick sort algo

    Bernstein(double a, double b, double c, double d, double e, double f); //deg 5
    Bernstein(double a, double b, double c, double d, double e);           //deg 4
    Bernstein(double a, double b, double c, double d);                     //deg 3
    Bernstein(double a, double b, double c);                               //deg 2
};

#endif