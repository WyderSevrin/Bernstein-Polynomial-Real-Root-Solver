#include "Bernstein.h"

int main()
{

    Bernstein deg2(1000000000.0, 5.0, -8000000000.0);
    deg2.root(0.0000001);
    deg2.showracine();

    return 0;
}