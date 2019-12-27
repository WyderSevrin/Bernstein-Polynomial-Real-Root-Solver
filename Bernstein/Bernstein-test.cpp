#include "Bernstein.h"

int main()
{

    Bernstein poly(0.5, 2, 1, 2, 10, -2);
    poly.root(0.01);
    poly.showracine();

    return 0;
}