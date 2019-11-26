#pragma once
#include <math.h>
#include <iostream>
class Poly3
{
public:
	Poly3(double a, double b, double c);
	Poly3(double a, double b, double c, double d);
	void solveViete();
	void cardanI(); //Avec imaginaire
	void cardan(); // sans imaginaire
	double root3(double x);
	double _root3(double x);

private:
	double m_a;
	double m_b;
	double m_c;
	double m_d;

	double x1;
	double x2;
	double x3;
};

