#include "Interval.h"

double Interval::getgauche() const //renvoie la valeur m_gauche
{
    return m_gauche;
}
double Interval::getdroite() const //renvoie la valeur m_droite
{

    return m_droite;
}
double Interval::getdelta() const //renvoie la valeur m_delta
{

    return m_delta;
}

void Interval::setgauche(double g) //definie la valeur m_gauche
{
    m_gauche = g;
}
void Interval::setdroite(double d) //definie la valeur m_delta
{
    m_droite = d;
}

Interval Interval::castelgauche() //permet de séparer l'interval en 2 ici le côté gauche
{
    return Interval(m_gauche, m_droite - (m_delta / 2.0));
}
Interval Interval::casteldroite() //permet de séparer l'interval en 2 ici le côté droite
{
    return Interval(m_gauche + (m_delta / 2.0), m_droite);
}

Interval::Interval(double g, double d) //constructeur de la classe
{
    m_gauche = g;
    m_droite = d;
    m_delta = d - g; //calcul de la difference
}

void Interval::showinterval() //permet d'afficher l'objet interval
{
    std::cout << "[ " << m_gauche << " , " << m_droite << " ]" << std::endl;
}