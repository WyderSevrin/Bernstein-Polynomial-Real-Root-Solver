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

    for (int i = 0; i < (controlpoint.getligne() - 1); i++) //on parcourt les points de controle du polynome de bernstein
    {

        if (((controlpoint.getcell(i, 0) > 0) && (controlpoint.getcell(i + 1, 0) <= 0)) || ((controlpoint.getcell(i, 0) < 0) && (controlpoint.getcell(i + 1, 0) >= 0))) //on regarde si il y a un changement de signe dans les points de controle
        {
            racine = true;
            coordYpointgauche = controlpoint.getcell(i, 0);     //definition de la coordonné y du point a gauche de y=0
            coordYpointdroite = controlpoint.getcell(i + 1, 0); //definition de la coordonné y du point a droite de y=0
            indice = i;                                         //indice de la valeur gauche où il y a la racine
            compteur++;                                         //si il a plusieurs racines dans l'interval on
        }
    }
    if (compteur > 1) //on teste si il y a plusieurs racines dans l'interval
    {
        racinemultiple = true;
    }
    //

    if (racine == true) //on teste si il y a une racine dans l'interval
    {
        // on arrete de calculer les nouveaux intervals si on dépasser la précision ou si il y a plusieurs racines dans l'interval et le nombre maximum d'iteration
        if (((interval.getdelta() > precision) || (racinemultiple == true)) && (m_maxiteration > m_iteration))
        {
            m_iteration++;                                                 //on incremmente m_iteration car on doit pour limiter le nombre de division de l'interval
            Matrice controlpointG = m_castelG * controlpoint;              //on calcul les nouveaux poit de control pour la partie gauche de l'interval c'est l'algorithme de Casteljau
            Matrice controlpointD = m_castelD * controlpoint;              //on calcul les nouveaux poit de control pour la partie droite de l'interval c'est l'algorithme de Casteljau
            rootfinder(controlpointG, interval.castelgauche(), precision); //on appel la fonction "rootfinder" pour recommencer les étapes mais cette fois ci avec l'interval gauche calculer précédament
            rootfinder(controlpointD, interval.casteldroite(), precision); //on appel la fonction "rootfinder" pour recommencer les étapes mais cette fois ci avec l'interval droite calculer précédament
        }
        else
        {
            //on trace un segment entre le point à gauche de y=0 et le point à droite de y=0
            double coordXpointgauche = interval.getgauche() + ((indice * interval.getdelta()) / (controlpoint.getligne() - 1));       //on calcul le point à gauche de y=0
            double coordXpointdroite = interval.getgauche() + (((indice + 1) * interval.getdelta()) / (controlpoint.getligne() - 1)); //on calcul le point à droite de y=0
            double pente = (coordYpointdroite - coordYpointgauche) / (coordXpointdroite - coordXpointgauche);                         //on calcul la pente entre les deux points
            double offset = coordYpointgauche - pente * coordXpointgauche;                                                            //on calcul "b" de y=ax+b
            double root = -1.0 * (offset / pente);                                                                                    //on calcul pour y=0 donc 0=-(b/a) ce qui donne la racine

            if (root != root) //si la valeur de la racine n'est pas defini alors on rentre dans le if car (a != nan) est toujours vrai
            {
                root = (interval.getgauche() + interval.getdelta() / 2); //on prend le milieu de l'interval
            }
            m_racine.push_back(root); //on ecrit la racine dans le tableau
        }
    }
}

void Bernstein::setmaxiteration(int i) //permet de modifier le nombre maximum d'iteration
{
    m_maxiteration = i;
}

void Bernstein::root(double precision) //permet de trouver les racines via la fonction "rootfinder"
{
    if (precision > 0) //teste de validité
    {
        Matrice controlpointG = m_invmG * m_coeff;       //calcul des points de control dans l'interval coté gauche
        rootfinder(controlpointG, m_originG, precision); //execution de l'algorithme pour trouvé les racines

        Matrice controlpointD = m_invmD * m_coeff;       //calcul des points de control dans l'interval coté droite
        rootfinder(controlpointD, m_originD, precision); //execution de l'algorithme pour trouvé les racines
    }
    else
    {
        std::cout << "erreur la valeur de la précision est negative" << std::endl;
    }
}

void Bernstein::showracine()
{
    std::cout << "il y a " << m_racine.size() << " racines" << std::endl;
    for (unsigned int i = 0; i < m_racine.size(); i++) //parcourt toutes les cases du tableau
    {
        std::cout << " racine " << i + 1 << " : " << m_racine[i] << " " << std::endl;
    }
}

//la methode des constructeurs est identique il n'y a que les matrices qui sont plus grandes

Bernstein::Bernstein(double a, double b, double c) //constructeur pour les polynomes de degré 2 //pas demandé
{
    m_maxiteration = 250;
    m_iteration = 0;
    m_coeff = Matrice(3, 1);
    m_castelG = initcastelGdeg2();
    m_castelD = initcastelDdeg2();
    m_coeff.setmat(1, 1, c);
    m_coeff.setmat(2, 1, b);
    m_coeff.setmat(3, 1, a);
    double coeffmax = maxinterval(m_coeff);
    m_origin = Interval(-1.0 * coeffmax, coeffmax);
    m_originG = Interval(m_origin.getgauche(), m_origin.castelgauche().getdroite());
    m_originD = Interval(m_origin.casteldroite().getgauche(), m_origin.getdroite());

    Matrice MG = initmdeg2(m_originG.getgauche(), m_originG.getdroite());
    m_invmG = inv(MG);
    Matrice MD = initmdeg2(m_originD.getgauche(), m_originD.getdroite());
    m_invmD = inv(MD);
}

Bernstein::Bernstein(double a, double b, double c, double d) //constructeur pour les polynomes de degré 3
{

    m_maxiteration = 430; //definintion du nombre d'iteration maximale
    m_iteration = 0;      //iteration acutel

    m_coeff = Matrice(4, 1); //definintion de la matrice de coefficient
    m_coeff.setmat(1, 1, d);
    m_coeff.setmat(2, 1, c);
    m_coeff.setmat(3, 1, b);
    m_coeff.setmat(4, 1, a);

    //definition des matrice de casteljau
    m_castelG = initcastelGdeg3();
    m_castelD = initcastelDdeg3();

    //calcul de l'interval [a,b] pour l'etude
    double coeffmax = maxinterval(m_coeff);                                          //calcul du efficient maximum
    m_origin = Interval(-1.0 * coeffmax, coeffmax);                                  //interval d'origine [a,b] centré sur 0
    m_originG = Interval(m_origin.getgauche(), m_origin.castelgauche().getdroite()); //interval [a,0] centré sur a/2
    m_originD = Interval(m_origin.casteldroite().getgauche(), m_origin.getdroite()); //interval [0,b] centré sur b/2

    //initialisation des matrices M pour faire le changement en polynome de Bernstein
    Matrice MG = initmdeg3(m_originG.getgauche(), m_originG.getdroite());
    m_invmG = inv(MG); // inversion de la matrice M de l'interval gauche
    Matrice MD = initmdeg3(m_originD.getgauche(), m_originD.getdroite());
    m_invmD = inv(MD); // inversion de la matrice M de l'interval droite
}

Bernstein::Bernstein(double a, double b, double c, double d, double e) //constructeur pour les polynomes de degré 4
{

    m_maxiteration = 690;
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

    Matrice MG = initmdeg4(m_originG.getgauche(), m_originG.getdroite());
    m_invmG = inv(MG);
    Matrice MD = initmdeg4(m_originD.getgauche(), m_originD.getdroite());
    m_invmD = inv(MD);
}

Bernstein::Bernstein(double a, double b, double c, double d, double e, double f) //constructeur pour les polynomes de degré 5
{
    m_maxiteration = 900;
    m_iteration = 0;

    m_coeff = Matrice(6, 1);
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

    Matrice MG = initmdeg5(m_originG.getgauche(), m_originG.getdroite());
    m_invmG = inv(MG);
    Matrice MD = initmdeg5(m_originD.getgauche(), m_originD.getdroite());
    m_invmD = inv(MD);
}