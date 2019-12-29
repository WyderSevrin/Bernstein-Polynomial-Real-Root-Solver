#ifndef INTERVALLE_H
#define INTERVALLE_H
#include "Fonction.h"

class Intervalle
{
private:
    double m_gauche; //valeur à gauche de l'intervalle [valeur gauche , valeur droite]
    double m_droite; //valeur à droite de l'intervalle [valeur gauche , valeur droite]
    double m_delta;  //valeur à de la différence entre les deux bornes de l'intervalle

public:
    double getgauche() const; //renvoie la valeur m_gauche
    double getdroite() const; //renvoie la valeur m_droite
    double getdelta() const;  //renvoie la valeur m_delta

    void setgauche(double g); //definie la valeur m_gauche
    void setdroite(double d); //definie la valeur m_droite

    void showintervalle(); //permet d'afficher l'objet intervalle

    Intervalle castelgauche(); //permet de séparer l'intervalle en 2 ici le côté gauche
    Intervalle casteldroite(); //permet de séparer l'intervalle en 2 ici le côté droite

    Intervalle(double g = 0.0, double d = 0.0); //constructeur de la classe
};

#endif