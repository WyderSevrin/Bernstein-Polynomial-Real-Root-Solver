#include "Poly2.h"

Poly2::Poly2(double a, double b, double c) :
	m_a(a),
	m_b(b),
	m_c(c)
{
	this->m_racines[0] = 0;
	this->m_racines[1] = 0;
}

void Poly2::solve() {
	double delta = pow(m_b, 2) - 4 * m_a * m_c;

	if (delta > 0) {
		double x1 = (-m_b - sqrt(delta)) / (2 * m_a);
		double x2 = (-m_b + sqrt(delta)) / (2 * m_a);
		this->m_racines[0] = x1;
		this->m_racines[0] = x2;
	}
	else if (delta == 0) {
		double x1 = (-m_b) / (2 * m_a);
		this->m_racines[0] = x1;
	}
	else {
		double x1 = 0;
		this->m_racines[0] = x1;
	}
}

void Poly2::getRacines(double racines[])
{
	racines = this->m_racines;
}

void Poly2::reset(double a, double b, double c)
{
	this->m_a = a;
	this->m_b = b;
	this -> m_c = c;
	this->m_racines[0] = 0;
	this->m_racines[1] = 0;
}
