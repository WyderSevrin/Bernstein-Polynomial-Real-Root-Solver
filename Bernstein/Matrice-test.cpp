#include "Matrice.h"

int main()
{
    Matrice gog(2, 2);
    Matrice lop(2, 1);

    gog.setmat(1, 1, 4);
    gog.setmat(1, 2, 6);
    gog.setmat(2, 1, 3);
    gog.setmat(2, 2, 1);
    //valide

    lop.setmat(1, 1, 9);
    lop.setmat(2, 1, 3);
    //valide

    //factor(2, gog).showmat(); //valide

    multiply(gog, lop).showmat(); //valide

    // multiply(lop, gog).showmat(); //impossible 2 1 2 2

    multiply(gog, gog).showmat(); //valide

    return 0;
}