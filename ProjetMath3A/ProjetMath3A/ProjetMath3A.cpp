// ProjetMath3A.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <string>
#include <stdlib.h>
#include "Poly3.h"
#include "Poly4.h"
#include "Poly5.h"

void solve3() {
	std::cout << "Faite votre choix en tapant le numero :\n";
	std::cout << "1_Cardan\n";
	std::cout << "4_Retour\n\n";

}
void solve4() {
	std::cout << "Faite votre choix en tapant le numero :\n";
	std::cout << "1_Ferrari\n";
	std::cout << "2_ \n";

	std::cout << "4_Retour\n\n";

}
void solve5() {
	std::cout << "Faite votre choix en tapant le numero :\n";
	std::cout << "1_Solver Multiple\n";
	std::cout << "4_Retour\n\n";

}



int main()
{
	std::string choix ="";
	while (choix != "4") {
		std::cout << "Resolution d'equation du 3eme degree au 5eme degree\n";
		std::cout << "Quels est le degree de l'equation à resoudre ?\n\n";

		std::cout << "1_Degree 3\n";
		std::cout << "2_Degree 4\n";
		std::cout << "3_Degree 5\n\n";
		std::cout << "4_Fermer l'application\n\n";
		std::cout << "\nFaite votre choix en tapant le numero :\n";

		std::cin >> choix;

		std::string choix2 = "";
		//////////////////////////////// DEGREE 3 /////////////////////////////////
		while (choix == "1") {
			solve3();
			std::cin >> choix2;
			
			if (choix2 != "4") {
				////////////////////// Cardan /////////
				if (choix2 == "1") {
					std::cout << "\nDonner l'equation :\n";
					std::cout << "aX^3 + bX^2 + c^X +d\n";
					double a, b, c, d = 0;
					std::cout << "a :\n";
					std::cin >> a;

					while (a == 0) {
						std::cout << "a doit pas etre 0, reprendre a :\n";
						std::cin >> a;
					}
					
					std::cout << "b :\n";
					std::cin >> b;
					std::cout << "c :\n";
					std::cin >> c;
					std::cout << "d :\n";
					std::cin >> d;

					Poly3 poly3(a, b, c, d);
					poly3.cardan();

					std::cout <<"\nContinuer ? tapez 1"<< std::endl;
					std::cin >> choix;
					if (choix != "1") {
						choix = "4";
					}

				}

			}
			else{
				choix = "0"; //retour
			}
		}
		//////////////////////////////// DEGREE 4 /////////////////////////////////
		while (choix == "2") {
			solve4();
			std::cin >> choix2;
			if (choix2 != "4") {
				/////////////////////Ferrari
				if (choix2 == "1") { 
					std::cout << "\nDonner l'equation :\n";
					std::cout << "aX^4 + bX^3+ cX^2 +dX +e\n";
					double a, b, c, d, e = 0;
					std::cout << "a :\n";
					std::cin >> a;

					while (a == 0) {
						std::cout << "a doit pas etre 0, reprendre a :\n";
						std::cin >> a;
					}

					std::cout << "b :\n";
					std::cin >> b;
					std::cout << "c :\n";
					std::cin >> c;
					std::cout << "d :\n";
					std::cin >> d;
					std::cout << "e :\n";
					std::cin >> e;

					Poly4 poly4(a, b, c, d,e);
					poly4.ferrrari(); 
				}
				else if (choix2 == "2") {
					std::cout << "PAS ENCORE IMPLEMENTER\n";
				}
				else if (choix2 == "3") {
					std::cout << "PAS ENCORE IMPLEMENTER\n";
				}
				
			}
			else {
				choix = "0"; //retour
			}
		}
		//////////////////////////////// DEGREE 5 /////////////////////////////////
		while (choix == "3") {
			solve5();
			std::cin >> choix2;
			if (choix2 != "4") {
				if (choix2 == "1") {
					std::cout << "\nDonner l'equation :\n";
					std::cout << "aX^5 + bX^4+ cX^3 +dX^2 +eX +f\n";
					double a, b, c, d, e,f = 0;
					std::cout << "a :\n";
					std::cin >> a;

					while (a == 0) {
						std::cout << "a doit pas etre 0, reprendre a :\n";
						std::cin >> a;
					}

					std::cout << "b :\n";
					std::cin >> b;
					std::cout << "c :\n";
					std::cin >> c;
					std::cout << "d :\n";
					std::cin >> d;
					std::cout << "e :\n";
					std::cin >> e;
					std::cout << "f :\n";
					std::cin >> f;
					Poly5 p5(a,b,c,d,e,f);
					p5.solve();
				}
				else{
					choix2 = "0";//retour
				}
			}
			else {
				choix = "0"; //retour
			}
		}
		system("CLS");
		
	}
	
	return 0;
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
