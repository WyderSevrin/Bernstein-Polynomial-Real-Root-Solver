#include "Poly4.h"



Poly4::Poly4(double a, double b, double c, double d, double e) :
	m_a(a),
	m_b(b),
	m_c(c),
	m_d(d),
	m_e(e)
{

}

void Poly4::ferrrari()
{
	double a = m_a;
	double b = m_b;
	double c = m_c;
	double d = m_d;
	double e = m_e;

	double root[10];

	if (m_a == 0) {
		Poly3 p3(m_b, m_c, m_d, m_e);
		double racinesP3[3]; //////////////////////////////////// RACINES
		p3.getRacines(racinesP3);
	}
	// Uses Ferrari's Method
	double aa = a * a, aaa = aa * a, bb = b * b, bbb = bb * b;
	double alpha = -3.0 * bb / (8.0 * aa) + c / a, alpha2 = alpha * alpha;
	double beta = bbb / (8.0 * aaa) + b * c / (-2.0 * aa) + d / a;
	double gamma = -3.0 * bbb * b / (256.0 * aaa * a) + c * bb / (16.0 * aaa) + b * d / (-4.0 * aa) + e / a;

	if (beta == 0.0)
	{
		root[0] = b / (-4.0 * a) + sqrt(0.5 * (-alpha + sqrt(alpha2 + 4.0 * gamma)));
	}
	else
	{
		double P = -alpha2 / 12.0 - gamma;
		double Q = -alpha2 * alpha / 108.0 + alpha * gamma / 3.0 - beta * beta / 8.0;
		double R = Q * 0.5 + sqrt(Q * Q * 0.25 + P * P * P / 27.0);
		double U = pow(R, 1.0 / 3.0);
		double y = -5.0 * alpha / 6.0 - U;
		if (U != 0.0) y += P / (3.0 * U);
		double W = sqrt(alpha + y + y);

		double aRoot;
		bool foundRealRoot = false;

		double firstPart = b / (-4.0 * a);
		double secondPart = -3.0 * alpha - 2.0 * y;
		double thirdPart = 2.0 * beta / W;

		aRoot = firstPart + 0.5 * (-W - sqrt(secondPart + thirdPart));
		root[0] = aRoot;

		aRoot = firstPart + 0.5 * (-W + sqrt(secondPart + thirdPart));
		root[1] = aRoot;

		aRoot = firstPart + 0.5 * (W - sqrt(secondPart - thirdPart));
		root[2] = aRoot;

		aRoot = firstPart + 0.5 * (W + sqrt(secondPart - thirdPart));
		root[3] = aRoot;
		
	}
	for (int i = 0; i < 4; i++) {
		std::cout << "Racines : " << root[i] << std::endl;
	}
}

void Poly4::methode2()
{
	double Roots[4];
	//Divide the equation by a
	double B = m_b / m_a;
	double C = m_c / m_a;
	double D = m_d / m_a;
	double E = m_e / m_a;

	double I = ((-3 * (B * B)) / 8) + C; // alpha
	double J = ((B*B*B) / 8) - (B * C / 2) + D; // beta
	double K = ((-3*(pow(B,4)))/256) + ((C*(B*B))/16) - ((B *D)/ 4) + E;

	Poly3 p3(1.0,2*I,I*I-4*K,-(J*J));
	double rootsp3[3];
	p3.getRacines(rootsp3);

	double z = rootsp3[0]; // on a besoins que d'une valeur

	double value = z * z * z + z * z * (I + I) + z * (I * I - 4 * K) - J * J;

	double p = sqrt(z);
	double r = -p;
	double q = (I + z - J / p) * 0.5;
	double s = (I + z + J / p) * 0.5;

	double aRoot;

	Poly2 p2(1.0, p, q);
	p2.solve();
	double aRoot1[2];
	p2.getRacines(aRoot1);
	double r1 = aRoot1[0];
	r1 -= B / 4.0;

	p2.reset(1.0, r, s);
	p2.solve();
	double aRoot2[2];
	p2.getRacines(aRoot2);
	double r2 = aRoot2[0];
	r2 -= B / 4.0;

	Roots[0] = r1; //A voir si on a besoins que d'une seule racine ou si on prend les deux et on oublie la partie d'après
	Roots[1] = r2;

	solveQuadraticDepreciate(1.0, p, q, aRoot);
	double r3 = aRoot;
	r3 -= B / 4.0;
	Roots[2] = r3;

	solveQuadraticDepreciate(1.0, r, s, aRoot);
	double r4 = aRoot;
	r4 -= B / 4.0;
	Roots[3] = r4;

	//Affichage
	for (int i = 0; i < 4; i++) {
		std::cout << "Racines : " << Roots[i] << std::endl;
	}
}

bool Poly4::solveQuadraticDepreciate(double a, double b, double c, double& root)
{
	if (a == 0.0 || abs(a / b) < 1.0e-4)
	{
		if (abs(b) < 1.0e-4)
			return false;
		else
		{
			root = -c / b;
			return true;
		}
	}

	double discriminant = b * b - 4.0 * a * c;
	if (discriminant >= 0.0)
	{
		discriminant = sqrt(discriminant);
		root = (b - discriminant) * -0.5 / a;
		return true;
	}

	return false;
}

