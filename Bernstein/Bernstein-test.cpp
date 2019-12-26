#include "Bernstein.h"

int main()
{

    Bernstein deg3(30000, 80, 1, -2);
    deg3.root(0.01);
    deg3.showracine();

    return 0;
}