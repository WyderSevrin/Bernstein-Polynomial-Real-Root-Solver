#pragma once
#include <iostream>
#include <math.h>
class Poly2
{
	

public:
	Poly2(double a, double b, double c);
	void solve();
	void getRacines(double racines[]);
	void reset(double a, double b, double c);
private:
	double m_a;
	double m_b;
	double m_c;


	double m_racines[2];
};

