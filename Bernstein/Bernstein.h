#ifndef BERNSTEIN_H
#define BERNSTEIN_H

#include "Matrice.h"
#include "Fonction.h"
#include "Interval.h"

class Bernstein
{
private:
    int m_iteration;                                                            //nombre de découpage d'interval
    int m_maxiteration;                                                         //nombre maximum de découpage d'interval //initialiser par le constructeur
    Matrice m_invmG;                                                            //matrice inverse de M pour le coté gauche de l'interval [a,b]
    Matrice m_invmD;                                                            //matrice inverse de M pour le coté droite de l'interval [a,b]
    Matrice m_castelG;                                                          //matrice pour faire l'algorithme de casteljau pour decouper l'interval en deux ici le coté gauche
    Matrice m_castelD;                                                          //matrice pour faire l'algorithme de casteljau pour decouper l'interval en deux ici le coté droite
    Matrice m_coeff;                                                            //matrice représentant les coefficients du polynome
    std::vector<double> m_racine;                                               // tableau stockant les racine
    Interval m_origin;                                                          //interval d'origine [a,b] normalement -a=b
    Interval m_originG;                                                         //interval d'origine coté gauche [a,0]
    Interval m_originD;                                                         //interval d'origine coté droite [0,b]
    void rootfinder(Matrice controlpoint, Interval interval, double precision); //permet de trouver les racines via une fonction récurente

public:
    void root(double precision); //permet de trouver les racines via la fonction "rootfinder"
    void showracine();           //affiche le contenu du tableau "m_racine"
    void setmaxiteration(int i); //permet de modifier le nombre maximum d'iteration

    Bernstein(double a, double b, double c, double d, double e, double f); //constructeur pour les polynomes de degré 5
    Bernstein(double a, double b, double c, double d, double e);           //constructeur pour les polynomes de degré 4
    Bernstein(double a, double b, double c, double d);                     //constructeur pour les polynomes de degré 3
    Bernstein(double a, double b, double c);                               //constructeur pour les polynomes de degré 2
};

#endif