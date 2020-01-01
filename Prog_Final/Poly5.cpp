#include "Poly5.h"

Poly5::Poly5(double a, double b, double c, double d, double e, double f) : 
	m_a(a),
	m_b(b),
	m_c(c),
	m_d(d),
	m_e(e),
	m_f(f)
{
}

void Poly5::solve()
{
	// Division des coefficients par a si a != 1
	if (m_a != 1.0)
	{
		m_b /= m_a;
		m_c /= m_a;
		m_d /= m_a;
		m_e /= m_a;
		m_f /= m_a;
		m_a /= m_a;
	}
	else {
		//Degree 4 et pas degree 5
	}

	double x0, equation[6] = { m_f, m_e, m_d, m_c, m_b, m_a };
	x0 = Newton(equation, 5, 0.5);
	printf("Une racine a ete trouvee : x1 = %lf\r\n\n", x0);

	double polynome[5];
	/* Factorisation par la m�thode de Horner */
	polynome[4] = m_a;
	polynome[3] = m_b + polynome[4] * x0;
	polynome[2] = m_c + polynome[3] * x0;
	polynome[1] = m_d + polynome[2] * x0;
	polynome[0] = m_e + polynome[1] * x0;


	printf("On factorise le polynome par la racine trouvee :\r\n\n");

	if (x0 < 0.0)
	{
		printf("(x+%lf)(", -x0);
	}
	else
	{
		printf("(x-%lf)(", x0);
	}

	afficheEquation('x', polynome, 4, 0);
	printf(") = 0\r\n\n");

	//degre4(polynome[4], polynome[3], polynome[2], polynome[1], polynome[0], variable, 'z', 'y', x0);
	double a = polynome[0];
	double b = polynome[1];
	double c = polynome[2];
	double d = polynome[3];
	double e = polynome[4];
	Poly4 p4(e, d, c, b, a);
	p4.ferrrari();
}



double Poly5::calculPoly(double polynome[6], int degree, double x) {
	double P = 0.0, S = 0.0;
	int cpt;
	for (cpt = degree; cpt >= 0; cpt--)
	{
		S = polynome[cpt] * pow(x, cpt);
		P = P + S;
	}
	return P;
}

// Quand tous les coefficients sont superieur a 0
double Poly5::Newton(double polynome[6], int degree, double x0) {
	double polynomeDeriv[6] = { 0.0 };
	int cpt, p;
	double xi, P = 0.0, P2 = 0.0, Pverif, Pverif2, Xi;
	xi = x0;
	int n = 0;

	p = degree - 1;
	for (cpt = p; cpt > 0; cpt--)
	{
		polynomeDeriv[cpt - 1] = polynome[cpt] * cpt;
	}

	do
	{
		n += 1;
		P = calculPoly(polynome, degree, xi);
		P2 = calculPoly(polynomeDeriv, p, xi);
		if (P < 0.0 && P2 < 0.0)
		{
			xi = xi + P / P2;
		}
		else
		{
			xi = xi - P / P2;
		}
		Pverif = P * pow(10.0, 7.0);
		Pverif2 = P * pow(10.0, 6.0);
		if (Pverif < 0.0)
		{
			Pverif = -Pverif;
		}

		if (Pverif2 < 0.0)
		{
			Pverif2 = -Pverif2;
		}

		if (xi < 0.0)
		{
			Xi = -xi;
		}
		else
		{
			Xi = xi;
		}

		if (Xi > 1000)
		{
			xi = -x0;
		}
	} while ((Pverif > 1.0 && Pverif2 >= 0) && n < 10000);

	// printf("P = %lf\r\nP2 = %lf\r\nx%i = %lf\r\n\n", P, P2, n, xi);
	return xi;
}

void Poly5::afficheEquation(char variable, double equation[6], int degree, int afficheZero = 1)
{
	int n;
	for (n = degree; n > 0; n--)
	{
		if (equation[n] != 0.0)
		{
			if (equation[n] == 1.0)
			{
				printf("%c", variable);
			}
			else if (equation[n] == -1.0)
			{
				printf("-%c", variable);
			}
			else
			{
				printf("%lf%c", equation[n], variable);
			}

			if (n > 1)
			{
				printf("^%i", n);
			}
		}

		if (equation[n - 1] > 0)
		{
			printf("+");
		}
	}

	if (equation[0] == 1.0)
	{
		printf("1");
	}
	else if (equation[0] == -1.0)
	{
		printf("-1");
	}
	else if (equation[0] != 0.0)
	{
		printf("%lf", equation[0]);
	}

	if (afficheZero == 1)
	{
		printf(" = 0\r\n\n");
	}
}
