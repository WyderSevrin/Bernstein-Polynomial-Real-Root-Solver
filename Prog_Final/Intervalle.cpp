#include "Intervalle.h"

double Intervalle::getgauche() const //renvoie la valeur m_gauche
{
    return m_gauche;
}
double Intervalle::getdroite() const //renvoie la valeur m_droite
{

    return m_droite;
}
double Intervalle::getdelta() const //renvoie la valeur m_delta
{

    return m_delta;
}

void Intervalle::setgauche(double g) //definie la valeur m_gauche
{
    m_gauche = g;
}
void Intervalle::setdroite(double d) //definie la valeur m_delta
{
    m_droite = d;
}

Intervalle Intervalle::castelgauche() //permet de séparer l'intervalle en 2 ici le côté gauche
{
    return Intervalle(m_gauche, m_droite - (m_delta / 2.0));
}
Intervalle Intervalle::casteldroite() //permet de séparer l'intervalle en 2 ici le côté droite
{
    return Intervalle(m_gauche + (m_delta / 2.0), m_droite);
}

Intervalle::Intervalle(double g, double d) //constructeur de la classe
{
    m_gauche = g;
    m_droite = d;
    m_delta = d - g; //calcul de la difference
}

void Intervalle::showintervalle() //permet d'afficher l'objet intervalle
{
    std::cout << "[ " << m_gauche << " , " << m_droite << " ]" << std::endl;
}