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
{}
Poly3::Poly3(double a, double b, double c, double d) :
	m_a(a),
	m_b(b),
	m_c(c),
	m_d(d)
{}



void Poly3::cardan()
{
	// les variables utilis�e //
	double p, q, det, u = 0;

	// les trois solutions avec le nombre de sol. //
	double X1 = 0;
	double X2 = 0;
	double X3 = 0;

	p = (m_c / m_a) - (pow(m_b, 2.0)) / (3.0 * pow(m_a, 2.0));
	q = (2.0 * pow(m_b, 3.0)) / (27.0 * pow(m_a, 3.0)) - (m_b * m_c) / (3.0 * pow(m_a, 2.0)) + m_d / m_a;
	det = pow(q, 2) / 4 + pow(p, 3) / 27;

	//Encadrement du determinant quand celui-ci est trop petit on le met a 0, permet d'arrondire autour de 0
	if((det < 1.3e-15  )&&(det > -1.3e-15 )){
		det = 0;
	}
	
	if (det > 0) //On obtient 1 racine
	{
		/* le teste suivant est utile car le c++ (comme le vb)
		 ne savent pas faire des racine cubique negatives ...*/
		if (sgn(-q * 0.5 + pow(det, 0.5)) == 1)
		{
			u = pow((-q * 0.5 + pow(det, 0.5)), (1. / 3.));
		}
		else
		{
			u = -pow(-(-q * 0.5 + pow(det, 0.5)), (1. / 3.));
		}
		X1 = -m_b / (3.0 * m_a) + u - (p / (3. * u));
		m_racine.push_back(X1);
	}
	else if (det == 0)
	{
		//Une racine simple et une racine double
		if(p<0){
			X1 = -m_b / (3. * m_a) + sgn(q) * pow((-p / 3.), 0.5);
			X2 = -m_b / (3. * m_a) - 2.0*sgn(q) * pow((-p / 3.), 0.5);
			m_racine.push_back(X1);
			m_racine.push_back(X1);
			m_racine.push_back(X2);

		}else if (p == 0){ //Racines triple

			if (sgn(q) == 1)
			{
				X1 = -m_b / (3.0 * m_a) - pow(q, (1.0 / 3.0));
			}
			else
			{
				X1 = -m_b / (3.0 * m_a) + pow(-q, (1.0 / 3.0));
			}
			m_racine.push_back(X1);
			m_racine.push_back(X1);
			m_racine.push_back(X1);
		}
	}else if (det < 0){

		double r = sqrt(-pow(p,3) / 27);		
		double t = 1. / 3. * acos(-q / (2. * r));
		//double t = 1. / 3. * acos(-q / 2. * pow(27. / (pow(-p, 3.)), 0.5)); //variante pour t

		//On admet 3 solutions, xk = - b/3a + Xk , j'appelle -b/3a alf
		double alf = -(m_b) / (3. * m_a);
		X1 = alf + 2. * sqrt(-p / 3.) * cos(t); //on multiplie par 2 car on cherche Xk =2a avec k=0
		X2 = alf + 2. * sqrt(-p / 3.) * cos(t+( 2. * PI) / 3.); // ici on a k = 1, on a donc  k*2 * PI
		X3 = alf + 2. * sqrt(-p / 3.) * cos(t+( 4. * PI) / 3.); // ici on a k = 2, on a donc k*2*PI
		
		/* 
		//Autre m�thode qui revient au m�me sans utiliser PI
		double omega = acos(-q / (2 * sqrt(pow(-p, 3) / 27)));
		X1 = vt + 2 * r * cos(omega / 3);
		X2 = vt - r * cos(omega / 3) + sqrt(p*( pow(cos(omega/3),2) ) - p );
		X3 = vt - r * cos(omega / 3) - sqrt(p * (pow(cos(omega / 3), 2)) - p);*/

		m_racine.push_back(X1);
		m_racine.push_back(X2);
		m_racine.push_back(X3);

	}	
}

//Permet de recuperer les racines obtenu
void Poly3::getRacines(double racines[])
{
	for (unsigned int i = 0; i < m_racine.size();i++) {
		racines[i] = this->m_racine.at(i);
	}
}

//Permet d'afficher les racines
void Poly3::afficherRacines(){
	int nbRacines = m_racine.size();
	std::cout<<"Il y a "<<nbRacines<<" racines"<<std::endl;
	for(int i = 0; i<nbRacines;i++){
		std::cout<<"|X"<<i+1<<" = "<<m_racine.at(i)<<std::endl;
	}
}

