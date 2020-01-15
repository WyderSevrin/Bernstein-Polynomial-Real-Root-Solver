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
	//On divise les quotients par a
	m_b /= m_a;
	m_c /= m_a;
	m_d /= m_a;
	m_e /= m_a;
	m_f /= m_a;
	m_a /= m_a;

	double x0, equation[6] = { m_f, m_e, m_d, m_c, m_b, m_a };
	x0 = Newton(equation, 5, 0.5);
	m_racine.push_back(x0);

	//== On Factorisation par la methode de Horner ==//
	double Hm_a = m_a;
	double Hm_b = m_b + Hm_a * x0;
	double Hm_c = m_c + Hm_b * x0;
	double Hm_d = m_d + Hm_c * x0;
	double Hm_e = m_e + Hm_d * x0;

	Poly4 p4(Hm_a, Hm_b, Hm_c, Hm_d, Hm_e);
	p4.ferrrari();
	int nbRacinedeg4 = p4.getRacines().size();
	for (int i = 0; i < nbRacinedeg4; i++)
	{
		m_racine.push_back(p4.getRacines().at(i));
	}
	//m_racine.insert(m_racine.end(),p4.getRacines().begin(),p4.getRacines().end()); Cette methode ne marche pas tous le temps ATTENTION !!
}

/*
	Permet de faire un calcule intermediaire pour f/f' + r; ici on calcule f
*/
double Poly5::calculduPoly(double polynome[6], int degree, double x) {
	double P = 0.0, S = 0.0;
	int cpt;
	for (cpt = degree; cpt >= 0; cpt--)
	{
		S = polynome[cpt] * pow(x, cpt);
		P += S;
	}
	return P;
}

double Poly5::Newton(double polynome[6], int degree, double x0) {
	double polynomeDeriv[6] = { 0.0 };
	int cpt, p;
	double xi, P = 0.0, P2 = 0.0, Pverif, Pverif2, Xi;
	xi = x0;
	int n = 0; //Nombre d'incrementation, generalement pas besoins d'etre trop elevee

	p = degree - 1;
	//On fait la deriver du polynome
	for (cpt = p; cpt > 0; cpt--)
	{
		polynomeDeriv[cpt - 1] = polynome[cpt] * cpt;
	}

	do
	{
		n += 1;
		P = calculduPoly(polynome, degree, xi);//Calcule de f
		P2 = calculduPoly(polynomeDeriv, p, xi);//Calcule de f'

		//xi est une valeur absolu, ou plutot P/P2
		if ((P < 0.0 && P2 < 0.0 )||(P > 0.0 && P2 > 0.0))
		{
			xi = xi + P / P2; //  ---> polynome/polynomeDerive + racineTemp
		}
		else
		{
			xi = xi - P / P2;//---> -polynome/polynomeDerive + racineTemp
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
	} while ((Pverif > 1.0 && Pverif2 >= 0) && n < 100000);
	//std::cout<<"P : "<<P<<std::endl;
	//std::cout<<"P2 : "<<P2<<std::endl;
	return xi;
}

//Permet d'afficher les racines
void Poly5::afficherRacines(){
	int nbRacines = m_racine.size();
	std::cout<<"|Il y a "<<nbRacines<<" racines"<<std::endl;
	for(int i = 0; i<nbRacines;i++){
		std::cout<<"|X"<<i+1<<" = "<<m_racine.at(i)<<std::endl;
	}
}
