#ifndef INTERVAL_H
#define INTERVAL_H
#include "Fonction.h"

class Interval
{
private:
    double m_gauche; //valeur à gauche de l'interval [valeur gauche , valeur droite]
    double m_droite; //valeur à droite de l'interval [valeur gauche , valeur droite]
    double m_delta;  //valeur à de la différence entre les deux bornes de l'interval

public:
    double getgauche() const; //renvoie la valeur m_gauche
    double getdroite() const; //renvoie la valeur m_droite
    double getdelta() const;  //renvoie la valeur m_delta

    void setgauche(double g); //definie la valeur m_gauche
    void setdroite(double d); //definie la valeur m_droite

    void showinterval(); //permet d'afficher l'objet interval

    Interval castelgauche(); //permet de séparer l'interval en 2 ici le côté gauche
    Interval casteldroite(); //permet de séparer l'interval en 2 ici le côté droite

    Interval(double g = 0.0, double d = 0.0); //constructeur de la classe
};

#endif