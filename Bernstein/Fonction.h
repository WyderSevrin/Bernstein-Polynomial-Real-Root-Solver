#ifndef FONCTION_H
#define FONCTION_H
#include "Matrice.h"

double maxinterval(Matrice &coeff);

double absolue(double a);

Matrice initcastelGdeg2();
Matrice initcastelDdeg2();
Matrice initcastelGdeg3();
Matrice initcastelDdeg3();
Matrice initcastelGdeg4();
Matrice initcastelDdeg4();
Matrice initcastelGdeg5();
Matrice initcastelDdeg5();

Matrice initmdeg2(double a, double b);
Matrice initmdeg3(double a, double b);
Matrice initmdeg4(double a, double b);
Matrice initmdeg5(double a, double b);

#endif