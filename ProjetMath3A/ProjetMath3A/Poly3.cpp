#include "Poly3.h"
#define	TwoPi  6.28318530717958648
#define PI	   3.141592653589793
const double eps = 1e-14;
// fonction pour avoir le signe d'un nombre (1 ou -1)
template <typename T> int sgn(T val) {
	return (T(0) < val) - (val < T(0));
}

Poly3::Poly3(double a, double b, double c) : 
	m_a(a),
	m_b(b),
	m_c(c)
{
}
Poly3::Poly3(double a, double b, double c, double d) :
	m_a(a),
	m_b(b),
	m_c(c),
	m_d(d)
{
}

void Poly3::cardanI()
{
	double p = 0;
	double q = 0;
	double m, n, u, v, gDelta, theta = 0;
	double x, y, z, re, im = 0;
	double k = 0;

	p = (m_c / m_a) - (pow(m_b, 2.0) / (3 * pow(m_a, 2.0)));
	q = ((2 * pow(m_b, 3.0)) / (27 * pow(m_a, 3.0))) - ((m_b * m_c) / (3 * pow(m_a, 2.0))) + (m_d / m_a);
	gDelta = 4 * pow(p, 3.0) + 27 * pow(q, 2.0);
	//gDelta =pow(p, 3.0)/27 + pow(q, 2.0)/4;
	m = ((-q) / 2) + (0.5) * sqrt(gDelta / 27);
	n = ((-q) / 2) - (0.5) * sqrt(gDelta / 27);
	u = pow(abs(m), 1.0 / 3);
	v = pow(abs(n), 1.0 / 3);

	if (gDelta > 0)
	{
		if (m < 0) {
			u = -u;
		}
		if (n < 0) {
			v = -v;
		}
		x = u + v;
		x += (-m_b) / (3 * m_a);
		//re = (-q) / 2;
		re = (-x) / 2;
		re += (-m_b) / (3 * m_a);
		im = (sqrt(3) / 2) * (u - v);
		
		std::cout << "1 racine reelle:\n    x = " << x << std::endl;
		//"1 racine reelle:\n    x = " + x + "");
		std::cout << "2 racines complexes:\n y = " << re << "-" << im << "i, z = " << re << "+" << im << "i" << std::endl;
		//"2 racines complexes:\n" +"    y = " + re + "-" + im + "i , z  = " + re + "+" + im + "i");

	}


	else if (gDelta == 0)
	{

		if (m_b == 0 && m_c == 0 && m_d == 0) {
			//x = y = z = 0;
			std::cout<<"1 racine reelle de multiplicite 3:\n"<<"x = y = z = 0 "<<std::endl;
		}
		else {
			x = (3 * q) / p;
			x += (-m_b) / (3 * m_a);
			y = (-3 * q) / (2 * p);
			y += (-m_b) / (3 * m_a);
			if (q != 0 && p != 0) { //Cas trivial
				std::cout << " 1 racine reelle simple : \n    x = " << x << std::endl;
				std::cout << "1 racine reelle double:\n    y = z = " << y << std::endl;
			}
			else if (q == 0 && p == 0) {
				std::cout << "Il y a une racine triple : " << "-1" << std::endl;
			}
		}

	}
	else
	{
		k = (3 * q) / ((2 * p) * sqrt((-p) / 3));
		//theta = acos(k);
		theta =acos(-q / 2. * pow(27. / (pow(-p, 3.)), 0.5));
		x = 2 * sqrt((-p) / 3) * cos(theta / 3);
		y = 2 * sqrt((-p) / 3.) * cos((theta + 2.*PI) / 3.);
		z = 2 * sqrt((-p) / 3.) * cos((theta + 4.*PI) / 3.);

		if (x > -1E-6 && x < 1E-6)
			x = 0.0;
		if (y > -1E-6 && y < 1E-6)
			y = 0.0;
		if (z > -1E-6 && z < 1E-6)
			z = 0.0;

		x += (-m_b) / (3 * m_a);
		y += (-m_b) / (3 * m_a);
		z += (-m_b) / (3 * m_a);
		std::cout << "3 racines reelles:\n    x = " << x <<" , y = "<< y <<" , z = "<< z <<std::endl;

	}


}

void Poly3::cardan()
{
	// les variables utilisée //
	double p, q, det, u = 0;

	// les trois solutions avec le nombre de sol. //
	double X1 = 0;
	double X2 = 0;
	double X3 = 0;

	p = (m_c / m_a) - (pow(m_b, 2.0)) / (3.0 * pow(m_a, 2.0));
	q = (2.0 * pow(m_b, 3.0)) / (27.0 * pow(m_a, 3.0)) - (m_b * m_c) / (3.0 * pow(m_a, 2.0)) + m_d / m_a;
	//std::cout << "b/3a" << m_b / (3.0 * m_a) << std::endl;
	if (p == 0)
	{
		if (sgn(q) == 1)
		{
			X1 = -m_b / (3.0 * m_a) - pow(q, (1.0 / 3.0));
		}
		else
		{
			X1 = -m_b / (3.0 * m_a) + pow(-q, (1.0 / 3.0));
		}
		std::cout << "Une solution trouvee!\n\nX1 = " << X1;
	}
	else
	{
		det = pow(q, 2.) / 4. + pow(p, 3) / 27.;

		if (det > 0)
		{
			/* le teste suivant est utile car le c++ (comme le vb)
			 ne savent pas faire des racine cubique négatives ...*/

			if (sgn(-q * 0.5 + pow(det, 0.5)) == 1)
			{
				u = pow((-q * 0.5 + pow(det, 0.5)), (1. / 3.));
			}
			else
			{
				u = -pow(-(-q * 0.5 + pow(det, 0.5)), (1. / 3.));
			}
			X1 = -m_b / (3.0 * m_a) + u - (p / (3. * u));
			std::cout << "Une solution trouvee!\n\nX1 = " << X1;
		}
		if (det == 0)
		{
			X1 = -m_b / (3. * m_a) + sgn(q) * pow((-p / 3.), 0.5);
			X2 = -m_b / (3. * m_a) - 2.0*sgn(q) * pow((-p / 3.), 0.5);
			std::cout << "Trois solutions trouvees dont une double!\n\nX1 et X2  = " << X1 <<" et "<< X1 << "\nX2 = " << X2;
		}
		if (det < 0)
		{
			double r = sqrt(-p / 3.);
			//double t = acos((-q)/(2*r));
			//double t = ((-q) / (2 * r));
			double vt = -(m_b) / (3. * m_a);

			double alf = 1. / 3. * acos(-q / 2. * pow(27. / (pow(-p, 3.)), 0.5));

			X1 = vt + 2. * sqrt(-p / 3.) * cos(alf);
			X2 = vt + 2. * sqrt(-p / 3.) * cos(alf+( 2. * PI) / 3.);
			X3 = vt + 2. * sqrt(-p / 3.) * cos(alf+( 4. * PI) / 3.);


			/* Autre méthode qui revient au même sans utiliser PI
			double omega = acos(-q / (2 * sqrt(pow(-p, 3) / 27)));
			X1 = vt + 2 * r * cos(omega / 3);
			X2 = vt - r * cos(omega / 3) + sqrt(p*( pow(cos(omega/3),2) ) - p );
			X3 = vt - r * cos(omega / 3) - sqrt(p * (pow(cos(omega / 3), 2)) - p);
			*/

			std::cout << "Trois solutions trouvees!\n\nX1 = " << X1 << "\nX2 = " << X2 << "\nX3 = " << X3;
		

		}
	}
	//permet de recuperer les racines pour des applications suivantes 
	this->m_racines[0] = X1;
	this->m_racines[1] = X2;
	this->m_racines[2] = X3;
}

void Poly3::getRacines(double racines[])
{
	for (int i = 0; i < 3;i++) {
		racines[i] = this->m_racines[i];
	}
	//racines = this->m_racines;
}

