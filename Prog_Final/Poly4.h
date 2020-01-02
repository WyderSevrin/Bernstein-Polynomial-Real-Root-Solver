#pragma once

#include <iostream>
#include <math.h>
#include "Poly3.h"
#include "Poly2.h"
class Poly4
{
	

public:
	Poly4(double a, double b, double c, double d, double e);
	void bicar(double a, double c);
	void ferrrari();
	double sizetab(double tab[]);
	void afficherRacines();
	std::vector<double> getRacines();
private:
	double m_a;
	double m_b;
	double m_c;
	double m_d;
	double m_e;

	double m_racines[4];
	std::vector<double> m_racine;
};

