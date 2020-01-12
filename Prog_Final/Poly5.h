#ifndef POLY5_H
#define POLY5_H

#include <math.h>
#include "Poly4.h"
#include "Poly3.h"

class Poly5
{

public :
	Poly5(double a, double b, double c, double d, double e, double f);
	void solve();
	double Newton(double polynome[6], int degree, double x0);
	double calculPoly(double polynome[6], int degree, double x);
	void afficherRacines();
private :
	
	double m_a;
	double m_b;
	double m_c;
	double m_d;
	double m_e;
	double m_f;

	double m_racines[5];
	std::vector<double> m_racine;
	void afficheEquation(char variable, double equation[6], int degree, int afficheZero);
};

#endif