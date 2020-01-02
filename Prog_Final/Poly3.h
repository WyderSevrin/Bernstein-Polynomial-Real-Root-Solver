#pragma once
#include <math.h>
#include <vector>
#include <iostream>
class Poly3
{
public:
	Poly3(double a, double b, double c);
	Poly3(double a, double b, double c, double d);
	void cardanI(); //Avec imaginaire
	void cardan(); // Sans imaginaire
	double root3(double x);
	double _root3(double x);

	void getRacines(double racines[]);
	void afficherRacines();
private:
	double m_a;
	double m_b;
	double m_c;
	double m_d;


	std::vector<double> m_racine;
	double m_racines[3];

};

