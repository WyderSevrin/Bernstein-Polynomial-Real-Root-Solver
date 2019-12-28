#include "Bernstein.h"

int main()
{

    Bernstein poly(0.5, 2, 1, 2, 10, -2); //creation de la classe polynome avec un polynome generateur
    poly.root(0.0000001);                 //trouve les racines
    poly.showracine();                    //affiche les racines

    return 0;
}