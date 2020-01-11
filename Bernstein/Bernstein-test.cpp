#include "Bernstein.h"

int main()
{

    Bernstein poly(4, 4, 4, -4, -4, -5); //creation de la classe polynome avec un polynome generateur
    poly.root(0.0000001);                //trouve les racines
    poly.showracine();                   //affiche les racines

    return 0;
}