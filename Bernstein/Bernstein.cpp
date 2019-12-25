#include "Bernstein.h"

void Bernstein::rootfinder(Matrice &controlpoint, Interval interval, double precision) //recurence!!//quick sort algo
{

    bool racine = false;
    bool racinemultiple = false;
    double coordYpointgauche = 0;
    double coordYpointdroite = 0;
    int compteur = 0;
    double indice = 0.0;

    //test racine et racine multiple genre  1 -1 1 -1 racine multiple et racine // + coorY des point// attention au 0

    for (int i = 0; i < (controlpoint.getline() - 1); i++)
    {

        if (((controlpoint.getcell(i, 0) >= 0) && (controlpoint.getcell(i + 1, 0) <= 0)) || ((controlpoint.getcell(i, 0) <= 0) && (controlpoint.getcell(i + 1, 0) >= 0)))
        {
            racine = true;
            coordYpointgauche = controlpoint.getcell(i, 0);
            coordYpointdroite = controlpoint.getcell(i + 1, 0);
            indice = i;
            compteur++;
        }
    }
    if (compteur > 1)
    {
        racinemultiple = true;
    }
    //

    if (racine == true) //max iterator
    {
        /*std::cout << " holla " << std::endl;
        controlpoint.showmat();
        interval.showinterval();*/

        if (((interval.getdelta() > precision) || (racinemultiple == true)) && (interval.getdelta() > 0.00000000001) && m_maxiteration > m_iteration) //si valeur des points de control trop elevé besoin de refaire la mat invm
        {
            m_iteration++;
            Matrice controlpointG = m_castelG * controlpoint;
            Matrice controlpointD = m_castelD * controlpoint;
            rootfinder(controlpointG, interval.castelgauche(), precision);
            rootfinder(controlpointD, interval.casteldroite(), precision);
        }
        else
        {
            double coordXpointgauche = interval.getgauche() + ((indice * interval.getdelta()) / (controlpoint.getline() - 1)); //pb ici  soit formule soit indice en int
            double coordXpointdroite = interval.getgauche() + (((indice + 1) * interval.getdelta()) / (controlpoint.getline() - 1));
            double pente = (coordYpointdroite - coordYpointgauche) / (coordXpointdroite - coordXpointgauche);
            double offset = coordYpointgauche - pente * coordXpointgauche;
            double root = -1.0 * (offset / pente);
            m_racine.push_back(root);
        }
    }
}

void Bernstein::root(double precision)
{
    if (precision > 0)
    {
        Matrice controlpoint = m_invm * m_coeff;
        rootfinder(controlpoint, m_origin, precision);
    }
    else
    {
        std::cout << "erreur sur la valeur de la précision" << std::endl;
    }
}

void Bernstein::showracine()
{
    std::cout << "il y a " << m_racine.size() << " racines" << std::endl;
    for (unsigned int i = 0; i < m_racine.size(); i++)
    {
        std::cout << " racine " << i + 1 << " : " << m_racine[i] << " " << std::endl;
    }
}

/*Bernstein::Bernstein( double a,  double b,  double c,  double d,  double e,  double f) //deg 5
{
}
Bernstein::Bernstein( double a,  double b,  double c,  double d,  double e) //deg 4
{
}
Bernstein::Bernstein( double a,  double b,  double c,  double d) //deg 3
{
}*/
Bernstein::Bernstein(double a, double b, double c) //deg 2
{
    m_maxiteration = 5000;
    m_iteration = 0;
    m_coeff = Matrice(3, 1);
    m_castelG = Matrice(3, 3);
    m_castelD = Matrice(3, 3);
    m_coeff.setmat(1, 1, c);
    m_coeff.setmat(2, 1, b);
    m_coeff.setmat(3, 1, a);
    double coeffmax = maxinterval(m_coeff);
    m_origin = Interval(-1.0 * coeffmax, coeffmax); // attention symetrie fait que des valeur sont egale a 0 et casse l'algo pour les racine //il faut diviser l'enssemble en 2 pour qu'il ny ai pas de sym
    m_invm = Matrice(3, 3);
    initinvmdeg2(m_origin.getgauche(), m_origin.getdroite(), m_invm);
    initcastelGdeg2(m_castelG);
    initcastelDdeg2(m_castelD);
}
