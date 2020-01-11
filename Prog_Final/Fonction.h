#ifndef FONCTION_H
#define FONCTION_H
#include "Matrice.h"

double maxintervalle(Matrice &coeff); //renvoie le coefficient la valeur la plus grande +1 , dans une matrice (m,1) qui servira a faire un intervalle

double absolue(double a); //renvoie la valeur absolue

Matrice initcastelGdeg2(); //renvoie la matrice de casteljau
Matrice initcastelDdeg2(); //renvoie la matrice de casteljau
Matrice initcastelGdeg3(); //renvoie la matrice de casteljau
Matrice initcastelDdeg3(); //renvoie la matrice de casteljau
Matrice initcastelGdeg4(); //renvoie la matrice de casteljau
Matrice initcastelDdeg4(); //renvoie la matrice de casteljau
Matrice initcastelGdeg5(); //renvoie la matrice de casteljau
Matrice initcastelDdeg5(); //renvoie la matrice de casteljau

Matrice initmdeg2(double a, double b); //renvoie la matrice de M d'intervalle [a,b]
Matrice initmdeg3(double a, double b); //renvoie la matrice de M d'intervalle [a,b]
Matrice initmdeg4(double a, double b); //renvoie la matrice de M d'intervalle [a,b]
Matrice initmdeg5(double a, double b); //renvoie la matrice de M d'intervalle [a,b]

#endif