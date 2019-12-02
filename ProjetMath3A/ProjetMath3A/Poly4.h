#pragma once

#include <iostream>
#include <math.h>
#include "Poly3.h"
#include "Poly2.h"
class Poly4
{
	

public:
	Poly4(double a, double b, double c, double d, double e);
	void ferrrari();
	void methode2();

private:
	double m_a;
	double m_b;
	double m_c;
	double m_d;
	double m_e;

	double m_racines[4];


	bool solveQuadraticDepreciate(double a, double b, double c, double& root);
};

