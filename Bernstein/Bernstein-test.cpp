#include "Bernstein.h"

int main()
{

    Bernstein poly(1, 109.5, 2416.0, -3985.5, -61025.0, 31200.0); //creation de la classe polynome avec un polynome generateur
    poly.root(0.0000001);                                         //trouve les racines
    poly.showracine();                                            //affiche les racines

    return 0;
}