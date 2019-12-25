#include "Matrice.h"

int main()
{
    Matrice gog(2, 2);
    Matrice lop(2, 1);
    Matrice sgd(4, 4);

    sgd.setmat(1, 1, 1);
    sgd.setmat(1, 2, 1);
    sgd.setmat(1, 3, 1);
    sgd.setmat(1, 4, -1);

    sgd.setmat(2, 1, 1);
    sgd.setmat(2, 2, 1);
    sgd.setmat(2, 3, -1);
    sgd.setmat(2, 4, 1);

    sgd.setmat(3, 1, 1);
    sgd.setmat(3, 2, -1);
    sgd.setmat(3, 3, 1);
    sgd.setmat(3, 4, 1);

    sgd.setmat(4, 1, -1);
    sgd.setmat(4, 2, 1);
    sgd.setmat(4, 3, 1);
    sgd.setmat(4, 4, 1);

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

    std::cout << determinant(gog) << std::endl; //valide -16

    std::cout << std::endl;
    std::cout << "Partie sgd" << std::endl;
    sgd.showmat();
    inv(sgd).showmat(); //valide

    return 0;
}