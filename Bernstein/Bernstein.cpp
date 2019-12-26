#include "Bernstein.h"

void Bernstein::rootfinder(Matrice controlpoint, Interval interval, double precision) //recurence!!//quick sort algo
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
        Matrice controlpointG = m_invmG * m_coeff;
        rootfinder(controlpointG, m_originG, precision);

        Matrice controlpointD = m_invmD * m_coeff;
        rootfinder(controlpointD, m_originD, precision);
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
    m_maxiteration = 500;
    m_iteration = 0;
    m_coeff = Matrice(3, 1);
    m_castelG = initcastelGdeg2();
    m_castelD = initcastelDdeg2();
    m_coeff.setmat(1, 1, c);
    m_coeff.setmat(2, 1, b);
    m_coeff.setmat(3, 1, a);
    double coeffmax = maxinterval(m_coeff);
    m_origin = Interval(-1.0 * coeffmax, coeffmax); // attention symetrie fait que des valeur sont egale a 0 et casse l'algo pour les racine //il faut diviser l'enssemble en 2 pour qu'il ny ai pas de sym
    m_originG = Interval(m_origin.getgauche(), m_origin.castelgauche().getdroite());
    m_originD = Interval(m_origin.casteldroite().getgauche(), m_origin.getdroite());

    Matrice MG = initmdeg2(m_originG.getgauche(), m_originG.getdroite());
    m_invmG = inv(MG);
    Matrice MD = initmdeg2(m_originD.getgauche(), m_originD.getdroite());
    m_invmD = inv(MD);
}

Bernstein::Bernstein(double a, double b, double c, double d)
{

    m_maxiteration = 250;
    m_iteration = 0;

    m_coeff = Matrice(4, 1);
    m_coeff.setmat(1, 1, d);
    m_coeff.setmat(2, 1, c);
    m_coeff.setmat(3, 1, b);
    m_coeff.setmat(4, 1, a);

    m_castelG = initcastelGdeg3();
    m_castelD = initcastelDdeg3();

    double coeffmax = maxinterval(m_coeff);
    m_origin = Interval(-1.0 * coeffmax, coeffmax);
    m_originG = Interval(m_origin.getgauche(), m_origin.castelgauche().getdroite());
    m_originD = Interval(m_origin.casteldroite().getgauche(), m_origin.getdroite());

    Matrice MG = initmdeg3(m_originG.getgauche(), m_originG.getdroite());
    m_invmG = inv(MG);
    Matrice MD = initmdeg3(m_originD.getgauche(), m_originD.getdroite());
    m_invmD = inv(MD);
}

Bernstein::Bernstein(double a, double b, double c, double d, double e)
{

    m_maxiteration = 500;
    m_iteration = 0;

    m_coeff = Matrice(5, 1);
    m_coeff.setmat(1, 1, e);
    m_coeff.setmat(2, 1, d);
    m_coeff.setmat(3, 1, c);
    m_coeff.setmat(4, 1, b);
    m_coeff.setmat(5, 1, a);

    m_castelG = initcastelGdeg4();
    m_castelD = initcastelDdeg4();

    double coeffmax = maxinterval(m_coeff);
    m_origin = Interval(-1.0 * coeffmax, coeffmax);
    m_originG = Interval(m_origin.getgauche(), m_origin.castelgauche().getdroite());
    m_originD = Interval(m_origin.casteldroite().getgauche(), m_origin.getdroite());

    Matrice MG = initmdeg4(m_originG.getgauche(), m_originG.getdroite()); // a test
    m_invmG = inv(MG);
    Matrice MD = initmdeg4(m_originD.getgauche(), m_originD.getdroite());
    m_invmD = inv(MD);
}

Bernstein::Bernstein(double a, double b, double c, double d, double e, double f)
{
    m_maxiteration = 1000;
    m_iteration = 0;

    m_coeff = Matrice(5, 1);
    m_coeff.setmat(1, 1, f);
    m_coeff.setmat(2, 1, e);
    m_coeff.setmat(3, 1, d);
    m_coeff.setmat(4, 1, c);
    m_coeff.setmat(5, 1, b);
    m_coeff.setmat(6, 1, a);

    m_castelG = initcastelGdeg5();
    m_castelD = initcastelDdeg5();

    double coeffmax = maxinterval(m_coeff);
    m_origin = Interval(-1.0 * coeffmax, coeffmax);
    m_originG = Interval(m_origin.getgauche(), m_origin.castelgauche().getdroite());
    m_originD = Interval(m_origin.casteldroite().getgauche(), m_origin.getdroite());

    Matrice MG = initmdeg5(m_originG.getgauche(), m_originG.getdroite()); // a test
    m_invmG = inv(MG);
    Matrice MD = initmdeg5(m_originD.getgauche(), m_originD.getdroite());
    m_invmD = inv(MD);
}