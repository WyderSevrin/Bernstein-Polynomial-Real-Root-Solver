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
    Matrice peta = 2 * gog; //valide
    peta.showmat();
    Matrice yotta = peta * (1.0 / 2.0); //valide // attention 1 =int 1.0 = float
    yotta.showmat();

    Matrice mega = gog * lop; //valide
    mega.showmat();

    // multiply(lop, gog).showmat(); //impossible 2 1 2 2
    Matrice giga = gog * gog; //valide
    giga.showmat();
    //valide
    return 0;
}