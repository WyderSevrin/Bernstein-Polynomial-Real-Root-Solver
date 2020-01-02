#include "Poly4.h"

template <typename T> int sgn(T val) {
	return (T(0) < val) - (val < T(0));
}

Poly4::Poly4(double a, double b, double c, double d, double e) :
	m_a(a),
	m_b(b),
	m_c(c),
	m_d(d),
	m_e(e)
{

}
void Poly4::bicar(double a, double c) {
	double delta = -4 * a * c;
	if (delta<0) {
		//pas de solution
		std::cout << "Pas de solution" << std::endl;
	}
	else {
		delta = sqrt(delta);
		double x12 = (-a + delta) / 2;
		double x32 = (-a - delta) / 2;
		bool t12 = 0;
		bool t22 = 0;
		
		double x1, x2, x3, x4 = 0;

		if (x12 >= 0) { 
			x1 = sqrt(x12); 
			x2 = -x1; 
			
			t12 = 1;
		}
		if (x32 >= 0 && t12 == 1) { 
			x3 = sqrt(x32); 
			x4 = -x3; 
			t22 = 1;
		}
		if (x32 >= 0) { 
			x3 = sqrt(x32); 
			x4 = -x3; 
		}
		if (t12 && t22) {
			//std::cout << "Il y a 4 racines : " << std::endl;
			m_racines[0] = x1;
			m_racines[1] = x2;
			m_racines[2] = x3;
			m_racines[3] = x4;
		}
		else if (t12) {
			m_racines[0] = x1;
			m_racines[1] = x2;
			//std::cout << "Il y a 2 racines : " << std::endl;
			//std::cout << "X1 : " << x1 <<"X2 : "<<x2<< std::endl;
		}
		else if (t22) {
			m_racines[0] = x3;
			m_racines[1] = x4;
			//std::cout << "Il y a 2 racines : " << std::endl;
			//std::cout << "X1 : " <<x3<<"X2 : "<<x4<< std::endl;
		}
	}
}
void Poly4::ferrrari()
{
	double A = (-3 * pow(m_b, 2)) / (8 * pow(m_a, 2)) + (m_c / m_a);
	double B = ((pow(m_b / 2, 3)) / pow(m_a, 3)) - ((0.5 * m_c * m_b) / pow(m_a, 2)) + (m_d / m_a);
	double C = (-3 * pow(m_b / (4 * m_a), 4)) + ((m_c * pow(m_b / 4, 2)) / pow(m_a, 3)) - ((0.25 * m_b * m_d) / pow(m_a, 2)) + (m_e / m_a);

	//std::cout << "A = " << A << "\n B = " << B << "\n C = " << C << std::endl;
	//Equation bicarr�e de la forme X^4+AX^2+C =0 avec X^2 = Y
	if (B == 1e-14) {
		std::cout << "Solution bicarre" << std::endl;
		bicar(A, C);

	}
	else {
		//Resolution du degr�e 3
		double a = 1;
		double b = -A;
		double c = -4 * C;
		double d = 4 * A * C - pow(B, 2);
		double bs = m_b / 4 / m_a;
		Poly3 p3(a, b, c, d);
		//std::cout << "Racines de la forme du polynome " << std::endl;
		p3.cardan();
		double racinesCardan[3];
		p3.getRacines(racinesCardan);

		double p = (c / a) - (pow(b, 2.0)) / (3.0 * pow(a, 2.0));
		double r = sqrt(-p / 3);
		//std::cout << "p = " << p << std::endl;
		double u;
		//for (int i = 0; i < 2; i++) {
		//	std::cout << "racines p3 x = " << racinesCardan[i] << std::endl;
		//}
		//si nb racines > 1
		if (sizetab(racinesCardan) > 1) {
			bool end = false;
			if (r == 0) {
				u = racinesCardan[0];
				//endFerrari();
				end = true;
			}
			if (racinesCardan[0] > A && end == false) {
				u = racinesCardan[0];
				//endFerrari();
				end = true;
			}
			if(end == false)
				u = racinesCardan[1];

			if (racinesCardan[2] > A && end == false) {
				u = racinesCardan[2];
			}
			
		}
		else { //si nb racines =1
			u = racinesCardan[0];
		}

		//endFerrari
		double uma = u - A;
		double z = B / (2 * uma);
		//std::cout << "z = " << z << std::endl;  //z pas la bonne valeur
		//std::cout << "u-A = " << uma << std::endl;

		//R�solution polynome Degr�e 2
		
		double d1 = uma - 4 * (z * sqrt(uma) + u / 2);
		double t1 = 0;
		double x1, x2, x3, x4 = 0;
		//std::cout << "bs : " << bs << std::endl;
		if (d1 >= 0) {
			x1 = (sqrt(uma) + sqrt(d1)) / 2 - bs ;
			x2 = (sqrt(uma) - sqrt(d1)) / 2 - bs ;
			
			t1 = 1;
		}
		double d2 = uma - 4 * (-z * sqrt(uma) + u / 2);
		double t2 = 0;
		if (d2 >= 0) {
			x3 = (-sqrt(uma) + sqrt(d2)) / 2 - bs ;
			x4 = (-sqrt(uma) - sqrt(d2)) / 2 - bs ;
			t2 = 1;
		}
		if (t1==0 && t2 == 0) {
			std::cout << "\n!!Pas de solutions pour degre 4 !!\n" << std::endl;

		}
		if (t1 * t2 == 0 && (t1 == 1 || t2 ==1))
		{
			//std::cout << "\nDeux solutions" << std::endl;
			
			if (t1 == 1) {
				m_racine.push_back(x1);
				m_racine.push_back(x2);
				//m_racines[1] = x2;
				//std::cout << "x1 = " << x1 << "\nx2 = " << x2 << std::endl;
			}
			if (t2 == 1) {
				m_racine.push_back(x3);
				m_racine.push_back(x4);
				//m_racines[0] = x3;
				//m_racines[1] = x4;
				//std::cout << "x1 = " << x3 << "\nx2 = " << x4 << std::endl;
			}
		}
		else if (t1 ==1 && t2 ==1)
		{
			m_racine.push_back(x1);
			m_racine.push_back(x2);
			m_racine.push_back(x3);
			m_racine.push_back(x4);
			//m_racines[0] = x1;
			//m_racines[1] = x2;
			//m_racines[2] = x3;
			//m_racines[3] = x4;
			//std::cout << "\nQuatre solutions!!!" << std::endl;
			//std::cout << "x1 = " << x1 << "\nx2 = " << x2 << std::endl;
			//std::cout << "x3 = " << x3 << "\nx4 = " << x4 << std::endl;

		}
	}
}
void Poly4::afficherRacines(){
	int nbRacines = m_racine.size();
	std::cout<<"Il y a "<<nbRacines<<" racines"<<std::endl;
	for(int i = 0; i<nbRacines;i++){
		std::cout<<"X"<<i+1<<" = "<<m_racine.at(i)<<std::endl;
	}
}
std::vector<double> Poly4::getRacines(){
	return m_racine;
}

double Poly4::sizetab(double tab[]) 
{
	double compteur = 0;
	for (int i = 0; i < 2; i++) {
		if (tab[i] != 0) {
			compteur++;
		}
	}
	return compteur;
}

