#ifndef INTERVAL_H
#define INTERVAL_H
#include "Fonction.h"

class Interval
{
private:
    double m_gauche;
    double m_droite;
    double m_delta;

public:
    double getgauche() const;
    double getdroite() const;
    double getdelta() const;

    void setgauche(double g);
    void setdroite(double d);

    Interval castelgauche();
    Interval castetdroite();

    Interval(double g = 0.0, double d = 0.0);
};

#endif