// ProjetMath3A.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <string>
#include <stdlib.h>
#include "Poly3.h"
#include "Poly4.h"
#include "Poly5.h"
#include "Bernstein.h"

void presstocontinue()
{
	std::cout << "Entrer n'importe quoi pour continuer" << std::endl;
	std::cin.ignore();
	std::cin.ignore();
}

int main()
{

	std::string quit = "";
	std::string exit = "";
	std::string choixmenu1 = "";
	std::string choixmenu2 = "";
	std::string choixmenu3 = "";
	std::string menu = "1";
	std::string poubelle = "";
	double a, b, c, d, e, f = 0;

	while (quit != "3")
	{ //boucle principal

		if (menu == "1")
		{

			choixmenu1 = "";
			choixmenu2 = "";
			choixmenu3 = "";
			std::cout << "|=========================================================================================|\n";
			std::cout << "|===================== Resolution d'equation du 3eme au 5eme degree ======================|\n";
			std::cout << "|=========================================================================================|\n|\n";
			std::cout << "|Ecriver 1 pour des exemples, 2 pour entrer un polynome quelconque\n|" << std::endl;
			std::cout << "|1_Exemples" << std::endl;
			std::cout << "|2_Polynome quelconque" << std::endl;
			std::cout << "|3_Fermer l'application\n|" << std::endl;
			std::cout << "|Faite votre choix en tapant le numero : ";
			std::cin >> choixmenu1;
		}
		if (choixmenu1 == "1")
		{

			menu = "0";
			std::cout << "|=========================================================================================|\n";
			std::cout << "|=========================================Exemple=========================================|\n";
			std::cout << "|=========================================================================================|\n";
			std::cout << "|1_Degree 3\n";
			std::cout << "|2_Degree 4\n";
			std::cout << "|3_Degree 5\n|\n";
			std::cout << "|4_Retourner au menu\n|\n";
			std::cin >> choixmenu2;

			if (choixmenu2 == "1")
			{
				std::cout << "|Choissiser l'une des equations suivantes :\n";
				std::cout << "|1_ 	x^3 -x^2 -x + 1 = 0\n";
				std::cout << "|2_ 	4x^3 - 5x^2 - 23x + 6 = 0\n";
				std::cout << "|3_ 	2x^3 + 15x^2 + 24x - 16 = 0\n";
				std::cout << "|4_ 	1x^3 + 3x^2 + 5x + 6 = 0\n";
				std::cout << "|Faite votre choix en tapant le numero : ";

				int choixEqua = 0;
				std::cin >> choixEqua;
				if (choixEqua == 1)
				{
					std::cout << "|\n|";
					std::cout << "Methode de Cardan" << std::endl;
					Poly3 poly3(1, -1, -1, 1);
					poly3.cardan();
					poly3.afficherRacines();
					std::cout << "|\n|";
					std::cout << "Methode de Bernstein" << std::endl;
					Bernstein poly(1, -1, -1, 1);
					poly.root(0.0000001);
					poly.showracine();
					std::cout << "|\n|";
				}
				else if (choixEqua == 2)
				{
					std::cout << "|\n|";
					std::cout << "Methode de Cardan" << std::endl;
					Poly3 poly3(4, -5, -23, 6);
					poly3.cardan();
					poly3.afficherRacines();
					std::cout << "|\n|";
					std::cout << "Methode de Bernstein" << std::endl;
					Bernstein poly(4, -5, -23, 6);
					poly.root(0.0000001);
					poly.showracine();
					std::cout << "|\n|";
				}
				else if (choixEqua == 3)
				{
					std::cout << "|\n|";
					std::cout << "Methode de Cardan" << std::endl;
					Poly3 poly3(2, 15, 24, -16);
					poly3.cardan();
					poly3.afficherRacines();
					std::cout << "|\n|";
					std::cout << "Methode de Bernstein" << std::endl;
					Bernstein poly(2, 15, 24, -1);
					poly.root(0.0000001);
					poly.showracine();
					std::cout << "|\n|";
				}
				else if (choixEqua == 4)
				{
					std::cout << "|\n|";
					std::cout << "Methode de Cardan" << std::endl;
					Poly3 poly3(1, 3, 5, 6);
					poly3.cardan();
					poly3.afficherRacines();
					std::cout << "|\n|";
					std::cout << "Methode de Bernstein" << std::endl;
					Bernstein poly(1, 3, 5, 6);
					poly.root(0.0000001);
					poly.showracine();
					std::cout << "|\n|";
				}
				presstocontinue();
			}
			if (choixmenu2 == "2")
			{
				std::cout << "|Choissisez l'une des equations suivantes :\n";
				std::cout << "|1_ 	3x^4 + 45x^3 - 24x^2 - 150x + 4 = 0\n";
				std::cout << "|2_ 	2567x^4 - 248x^3 - 123x^2 + 68x + 854 = 0\n";
				std::cout << "|3_ 	-653x^4 + 234x^3 - 24x^2 - 955x + 12 = 0\n";
				std::cout << "|4_ 	24x^4 + 34x^3 -345x^2 -12x + 45 = 0\n";
				std::cout << "|Faite votre choix en tapant le numero : ";
				int choixEqua = 0;
				std::cin >> choixEqua;
				std::cout << "|\n";
				if (choixEqua == 1)
				{
					std::cout << "|\n|";
					std::cout << "Methode de Ferrari" << std::endl;
					Poly4 poly4(3, 45, -24, -150, 4);
					poly4.ferrrari();
					poly4.afficherRacines();
					std::cout << "|\n|";
					std::cout << "Methode de Bernstein" << std::endl;
					Bernstein poly(3, 45, -24, -150, 4);
					poly.root(0.0000001);
					poly.showracine();
					std::cout << "|\n|";
				}
				else if (choixEqua == 2)
				{
					std::cout << "|\n|";
					std::cout << "Methode de Ferrari" << std::endl;
					Poly4 poly4(2567, -248, -123, 68, 854);
					poly4.ferrrari();
					poly4.afficherRacines();
					std::cout << "|\n|";
					std::cout << "Methode de Bernstein" << std::endl;
					Bernstein poly(2567, -248, -123, 68, 854);
					poly.root(0.0000001);
					poly.showracine();
					std::cout << "|\n|";
				}
				else if (choixEqua == 3)
				{
					std::cout << "|\n|";
					std::cout << "Methode de Ferrari" << std::endl;
					Poly4 poly4(-653, 234, -24, -955, 12);
					poly4.ferrrari();
					poly4.afficherRacines();
					std::cout << "|\n|";
					std::cout << "Methode de Bernstein" << std::endl;
					Bernstein poly(-653, 234, -24, -955, 12);
					poly.root(0.0000001);
					poly.showracine();
					std::cout << "|\n|";
				}
				else if (choixEqua == 4)
				{
					std::cout << "|\n|";
					std::cout << "Methode de Ferrari" << std::endl;
					Poly4 poly4(24, 34, -345, -12, 45);
					poly4.ferrrari();
					poly4.afficherRacines();
					std::cout << "|\n|";
					std::cout << "Methode de Bernstein" << std::endl;
					Bernstein poly(24, 34, -345, -12, 45);
					poly.root(0.0000001);
					poly.showracine();
					std::cout << "|\n|";
				}
				presstocontinue();
			}
			if (choixmenu2 == "3")
			{
				std::cout << "|Choissisez l'une des equations suivantes :\n";
				std::cout << "|1_ 	24x^5 - 67x^4 + 45x^3 - 24x^2 - 150x + 4 = 0\n";
				std::cout << "|2_ 	-567x^5 + 237x^4 - 248x^3 - 153x^2 + 68x + 54 = 0\n";
				std::cout << "|3_ 	765x^5 - 653x^4 + 234x^3 + 24x^2 - 955x + 12 = 0\n";
				std::cout << "|4_ 	-2x^5 + 24x^4 + 34x^3 -345x^2 -182x + 45 = 0\n";
				std::cout << "|Faite votre choix en tapant le numero : ";

				int choixEqua = 0;
				std::cin >> choixEqua;
				std::cout << "|\n";
				if (choixEqua == 1)
				{
					std::cout << "|\n|";
					std::cout << "Methode de Newton" << std::endl;
					Poly5 p5(24, -67, 45, -24, -150, 4);
					p5.solve();
					p5.afficherRacines();
					std::cout << "|\n|";
					std::cout << "Methode de Bernstein" << std::endl;
					Bernstein poly(24, -67, 45, -24, -150, 4);
					poly.root(0.0000001);
					poly.showracine();
					std::cout << "|\n|";
				}
				else if (choixEqua == 2)
				{
					std::cout << "|\n|";
					std::cout << "Methode de Newton" << std::endl;
					Poly5 p5(-567, 237, -248, -153, 68, 54);
					p5.solve();
					p5.afficherRacines();
					std::cout << "|\n|";
					std::cout << "Methode de Bernstein" << std::endl;
					Bernstein poly(-567, 237, -248, -153, 68, 54);
					poly.root(0.0000001);
					poly.showracine();
					std::cout << "\n|";
				}
				else if (choixEqua == 3)
				{
					std::cout << "|\n|";
					std::cout << "Methode de Newton" << std::endl;
					Poly5 p5(765, -653, 234, 24, -955, 12);
					p5.solve();
					p5.afficherRacines();
					std::cout << "|\n|";
					std::cout << "Methode de Bernstein" << std::endl;
					Bernstein poly(765, -653, 234, 24, -955, 12);
					poly.root(0.0000001);
					poly.showracine();
					std::cout << "\n|";
				}
				else if (choixEqua == 4)
				{
					std::cout << "|\n|";
					std::cout << "Methode de Newton" << std::endl;
					Poly5 p5(-2, 24, 34, -345, -182, 45);
					p5.solve();
					p5.afficherRacines();
					std::cout << "|\n|";
					std::cout << "Methode de Bernstein" << std::endl;
					Bernstein poly(-2, 24, 34, -345, -182, 45);
					poly.root(0.0000001);
					poly.showracine();
					std::cout << "|\n|";
				}
				presstocontinue();
			}
			if (choixmenu2 == "4")
			{
				choixmenu1 = "0";
				menu = "1";
			}
		}
		if (choixmenu1 == "2")
		{
			menu = "0";
			std::cout << "|Quels est le degree de l'equation à resoudre ?\n|\n";

			std::cout << "|1_Degree 3\n";
			std::cout << "|2_Degree 4\n";
			std::cout << "|3_Degree 5\n|\n";
			std::cout << "|4_Retourner au menu\n|\n";
			std::cout << "|Faite votre choix en tapant le numero : ";
			std::cin >> choixmenu3;
			std::cout << "|\n|";
			if (choixmenu3 == "1")
			{
				std::cout << "\n|Donner l'equation :\n";
				std::cout << "|aX^3 + bX^2 + c^X +d\n";
				std::cout << "|a : ";
				std::cin >> a;

				while (a == 0)
				{
					std::cout << "a doit pas etre 0, reprendre a :\n";
					std::cin >> a;
				}

				std::cout << "|b : ";
				std::cin >> b;
				std::cout << "|c : ";
				std::cin >> c;
				std::cout << "|d : ";
				std::cin >> d;
				std::cout << "|\n|";
				std::cout << "Methode de Cardan" << std::endl;
				Poly3 poly3(a, b, c, d);
				poly3.cardan();
				poly3.afficherRacines();
				std::cout << "|\n|";
				std::cout << "Methode de Bernstein" << std::endl;
				Bernstein poly(a, b, c, d);
				poly.root(0.0000001);
				poly.showracine();
				std::cout << "|\n|";
				presstocontinue();
			}
			if (choixmenu3 == "2")
			{
				std::cout << "\n|Donner l'equation :\n";
				std::cout << "|aX^4 + bX^3+ cX^2 +dX +e\n";
				std::cout << "|a : ";
				std::cin >> a;

				while (a == 0)
				{
					std::cout << "|a doit pas etre 0, reprendre a :\n";
					std::cin >> a;
				}

				std::cout << "|b : ";
				std::cin >> b;
				std::cout << "|c : ";
				std::cin >> c;
				std::cout << "|d : ";
				std::cin >> d;
				std::cout << "|e : ";
				std::cin >> e;
				std::cout << "|\n|";
				std::cout << "Methode de Ferrari" << std::endl;
				Poly4 poly4(a, b, c, d, e);
				poly4.ferrrari();
				poly4.afficherRacines();
				std::cout << "|\n|";
				std::cout << "Methode de Bernstein" << std::endl;
				Bernstein poly(a, b, c, d, e);
				poly.root(0.0000001);
				poly.showracine();
				std::cout << "|\n|";
				presstocontinue();
			}
			if (choixmenu3 == "3")
			{
				std::cout << "\n|Donner l'equation :\n";
				std::cout << "|aX^5 + bX^4+ cX^3 +dX^2 +eX +f\n";
				std::cout << "|a : ";
				std::cin >> a;

				while (a == 0)
				{
					std::cout << "|a doit pas etre 0, reprendre a :\n";
					std::cin >> a;
				}

				std::cout << "|b : ";
				std::cin >> b;
				std::cout << "|c : ";
				std::cin >> c;
				std::cout << "|d : ";
				std::cin >> d;
				std::cout << "|e : ";
				std::cin >> e;
				std::cout << "|f : ";
				std::cin >> f;
				std::cout << "|\n|";
				std::cout << "Methode de Newton" << std::endl;
				Poly5 p5(a, b, c, d, e, f);
				p5.solve();
				p5.afficherRacines();
				std::cout << "|\n|";
				std::cout << "Methode de Bernstein" << std::endl;
				Bernstein poly(a, b, c, d, e, f);
				poly.root(0.0000001);
				poly.showracine();
				std::cout << "|\n|";
				presstocontinue();
			}

			if (choixmenu3 == "4")
			{
				choixmenu1 = "0";
				menu = "1";
			}
		}

		if (choixmenu1 == "3")
		{
			quit = "3";
		}
	}
	return 0;
}