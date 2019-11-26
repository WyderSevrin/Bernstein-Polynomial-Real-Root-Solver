#include "Bernoulli.h"
/*

Bernoulli::Bernoulli(double a, double b, double c)
{
	float a[4], x[100], erreur, x1, x2;
	int i, choix, nb_it;
	printf("\nVotre polynome est de la forme : P(x) = a[0]*x^3+a[1]*x^2+a[2]*x^1+a[3]\n");
	printf("\n===> Saisir les coefficients : \n\n");
	for (i = 0; i < 4; i++)
	{
		printf("\t a[%d] = ", i);
		scanf("%f", &a[i]);
	}
	printf("\nVotre polynome est : P(x) = %.2f*x^3+%.2f*x^2+%.2f*x^1+%.2f\n", a[0], a[1], a[2], a[3]);
	printf("\n===> Choix de la methode : \n\n\t1 : La condition d'erreur \n\t2 : La condition du nombre d'iterations \n\n\tChoix : ");
	scanf("%d", &choix);
	switch (choix)
	{
	case 1: printf("\nSaisir l'erreur de calcul : "); scanf("%f", &erreur); break;
	case 2: printf("\nSaisir le nombre d'iterations : "); scanf("%d", &nb_it); break;
	}
	printf("\n===> Saisir les premiers termes : \n\n");
	for (i = 0; i < 3; i++)
	{
		printf("\t x[%d] = ", i);
		scanf("%f", &x[i]);
	}
	i = 0;
	do
	{
		x[3 + i] = (-1 / a[0]) * (a[1] * x[2 + i] + a[2] * x[1 + i] + a[3] * x[0 + i]);
		x[3 + i + 1] = (-1 / a[0]) * (a[1] * x[2 + i + 1] + a[2] * x[1 + i + 1] + a[3] * x[0 + i + 1]);
		x[3 + i + 2] = (-1 / a[0]) * (a[1] * x[2 + i + 2] + a[2] * x[1 + i + 2] + a[3] * x[0 + i + 2]);
		x1 = x[3 + i + 1] / x[3 + i]; x2 = x[3 + i + 2] / x[3 + i + 1];
		i++;
	} while (fabs(x1 - x2) > erreur || i < nb_it);

	printf("\n===> La racine du plus grand module est : x* = %f\n\n", x1);
	Horner(x2, a);
}

void Bernoulli::Horner()
{
	// x_b la racine de plus grand module obtenue par Bernoulli
	int i;
	float b[4], x[2];

	printf("\nLe polynome de Horner s'%ccrit : \n\n\tP(x) = (x - x*) * Q(x) + R \n", 130);
	b[0] = a[0];
	for (i = 0; i < 4; i++)
	{
		b[i] = b[i - 1] * x_b + a[i];
	}

	// Affichage des coefficients de Bernoulli
	printf("\n===> Les coefficients de Horner :\n\n");
	for (i = 0; i < 4; i++)
	{
		printf("\n\tb[%d] = %f", i, b[i]);
	}
	printf("\n");
	printf("\nLe polynome d'Horner devient : \n\n\tP(x) = (x - %.2f) * (%.2f * x^2 + %.2f * x^1 + %.2f) + %.2f\n", x_b, b[0], b[1], b[2], b[3]);
	poly2(b);
}

void Bernoulli::Poly2()
{
	float x[2];
	int i;
	float delta;
	delta = a[1] * a[1] - 4 * a[0] * a[2];
	if (delta > 0)
	{

		printf("\n===> Le polynome admet 2 solutions :\n\n");
		x[0] = (-a[1] - sqrt(delta)) / (2 * a[0]);
		x[1] = (-a[1] + sqrt(delta)) / (2 * a[0]);
		printf("\tx[1] = %f\tx[2] = %f\n\n", x[0], x[1]);
	}
	else if (delta == 0)
	{
		x[2] = (-a[1]) / (2 * a[0]);
		printf("\n===> Le polynome admet une racine double : x = %f\n\n", x[2]);
	}
	else
	{
		printf("\n===> Le polynome n'admet pes de racine r%cele\n\n", 130);
	}

	
}
*/