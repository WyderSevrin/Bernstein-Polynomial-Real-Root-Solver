#include "Bernstein.h"

int main()
{

    Bernstein deg2(-6.0, 40.0, 8.0);
    deg2.root(0.00000001);
    deg2.showracine();
    return 0;
}