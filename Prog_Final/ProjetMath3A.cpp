// ProjetMath3A.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <string>
#include <stdlib.h>
#include "Poly3.h"
#include "Poly4.h"
#include "Poly5.h"
#include "Bernstein.h"

void solve3() {
	std::cout << "|=======================================\n";
	std::cout << "|Les methodes disponibles :\n";
	std::cout << "|1_Cardan\n";
	std::cout << "|2_Bernstein\n";
	std::cout << "|4_Retour\n|\n";
	std::cout << "|Faite votre choix en tapant le numero : ";

}
void solve4() {
	std::cout << "|=======================================\n";
	std::cout << "|Les methodes disponibles :\n";
	std::cout << "|1_Ferrari\n";
	std::cout << "|2_Bernstein\n";
	std::cout << "|4_Retour\n|\n";
	std::cout << "|Faite votre choix en tapant le numero : ";

}
void solve5() {
	std::cout << "|=======================================\n";
	std::cout << "|Les methodes disponibles :\n";
	std::cout << "|1_Methode de Newton\n";
	std::cout << "|2_Bernstein\n";
	std::cout << "|4_Retour\n|\n";
	std::cout << "|Faite votre choix en tapant le numero : ";
}



int main()
{
	std::string choix ="";
	while (choix != "4") {
		std::cout << "|=========================================================================================\n";
		std::cout << "|===================== Resolution d'equation du 3eme au 5eme degree ======================\n";
		std::cout << "|=========================================================================================\n|\n";
		std::cout << "|Quels est le degree de l'equation à resoudre ?\n|\n";

		std::cout << "|1_Degree 3\n";
		std::cout << "|2_Degree 4\n";
		std::cout << "|3_Degree 5\n|\n";
		std::cout << "|4_Fermer l'application\n|\n";
		std::cout << "|Faite votre choix en tapant le numero : ";

		std::cin >> choix;
		std::cout << "|\n";
		std::string choix2 = "";
		//////////////////////////////// DEGREE 3 /////////////////////////////////
		while (choix == "1") {


			solve3();
			std::cin >> choix2;
			std::cout << "|\n";
			
			if (choix2 != "4") {
				double a, b, c, d = 0;
				////////////////////// Cardan /////////
				if (choix2 == "1") {
					std::cout << "|1_Resoudre un polynome :\n";
					std::cout << "|2_Exemples :\n";
					std::cout << "|Faite votre choix en tapant le numero : ";
					int choix3 =0;
					std::cin >> choix3;
					std::cout << "|\n";

					if(choix3 == 1){
						std::cout << "\n|Donner l'equation :\n";
						std::cout << "|aX^3 + bX^2 + c^X +d\n";	
						std::cout << "|a : ";
						std::cin >> a;

						while (a == 0) {
							std::cout << "|a doit pas etre 0, reprendre a :\n";
							std::cin >> a;
						}
						std::cout << "|b : ";
						std::cin >> b;
						std::cout << "|c : ";
						std::cin >> c;
						std::cout << "|d : ";
						std::cin >> d;

						Poly3 poly3(a, b, c, d);
						poly3.cardan();
						poly3.afficherRacines();
					}else if(choix3 == 2){
						std::cout << "|Choissisez l'une des equations suivantes :\n";
						std::cout << "|1_ 	x^3 -x^2 -x + 1 = 0\n";
						std::cout << "|2_ 	4x^3 - 5x^2 - 23x + 6 = 0\n";
						std::cout << "|3_ 	2x^3 + 15x^2 + 24x - 16 = 0\n";
						std::cout << "|4_ 	1x^3 + 3x^2 + 5x + 6 = 0\n";
						std::cout << "|Faite votre choix en tapant le numero : ";

						int choixEqua = 0;
						std::cin>>choixEqua;
						if(choixEqua == 1){
							Poly3 poly3(1, -1, -1, 1);
							poly3.cardan();
							poly3.afficherRacines();
						}else if(choixEqua == 2){
							Poly3 poly3(4, -5, -23, 6);
							poly3.cardan();
							poly3.afficherRacines();
						}else if(choixEqua == 3){
							Poly3 poly3(2, 15, 24, -16);
							poly3.cardan();
							poly3.afficherRacines();
						}else if(choixEqua == 4){
							Poly3 poly3(1, 3, 5, 6);
							poly3.cardan();
							poly3.afficherRacines();
						}
					}

				}else if (choix2 == "2") { //Méthode de Berntein
					std::cout << "|1_Resoudre un polynome \n";
					std::cout << "|2_Exemples \n";
					std::cout << "|Faite votre choix en tapant le numero : ";

					int choix3 = 0;
					std::cin >> choix3;
					std::cout << "|\n";
					if(choix3 == 1){
						std::cout << "\n|Donner l'equation :\n";
						std::cout << "|aX^3 + bX^2 + c^X +d\n";
						std::cout << "|a : ";
						std::cin >> a;

						while (a == 0) {
							std::cout << "a doit pas etre 0, reprendre a :\n";
							std::cin >> a;
						}
						
						std::cout << "|b : ";
						std::cin >> b;
						std::cout << "|c : ";
						std::cin >> c;
						std::cout << "|d : ";
						std::cin >> d;
						Bernstein poly(a, b, c, d);
						poly.root(0.0000001);
						poly.showracine();
					} else if(choix3 == 2){
						std::cout << "|Choissisez l'une des equations suivantes :\n";
						std::cout << "|1_ 	x^3 -x^2 -x + 1 = 0\n";
						std::cout << "|2_ 	4x^3 - 5x^2 - 23x + 6 = 0\n";
						std::cout << "|3_ 	2x^3 + 15x^2 + 24x - 16 = 0\n";
						std::cout << "|4_ 	1x^3 + 3x^2 + 5x + 6 = 0\n";
						std::cout << "|Faite votre choix en tapant le numero : ";

						int choixEqua = 0;
						std::cin>>choixEqua;
						std::cout << "|\n";
						if(choixEqua == 1){
							Bernstein poly(1, -1, -1, 1);
							poly.root(0.0000001);
							poly.showracine();
						}else if(choixEqua == 2){
							Bernstein poly(4, -5, -23, 6);
							poly.root(0.0000001);
							poly.showracine();
						}else if(choixEqua == 3){
							Bernstein poly(2, 15, 24, -1);
							poly.root(0.0000001);
							poly.showracine();
						}else if(choixEqua == 4){
							Bernstein poly(1, 3, 5, 6);
							poly.root(0.0000001);
							poly.showracine();
						}
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
			std::cout << "|\n";
			if (choix2 != "4") {
				/////////////////////Ferrari
				if (choix2 == "1") { 
					std::cout << "|1_Resoudre un polynome \n";
					std::cout << "|2_Exemples \n";
					std::cout << "|Faite votre choix en tapant le numero : ";
					int choix3 =0;
					std::cin >> choix3;
					std::cout << "|\n";

					if(choix3 == 1){
						std::cout << "\n|Donner l'equation :\n";
						std::cout << "|aX^4 + bX^3+ cX^2 +dX +e\n";
						double a, b, c, d, e = 0;
						std::cout << "|a : ";
						std::cin >> a;

						while (a == 0) {
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

						Poly4 poly4(a, b, c, d,e);
						poly4.ferrrari();
						poly4.afficherRacines();
					}else if(choix3 == 2){
						std::cout << "|Choissisez l'une des equations suivantes :\n";
						std::cout << "|1_ 	3x^4 + 45x^3 - 24x^2 - 150x + 4 = 0\n";
						std::cout << "|2_ 	2567x^4 - 248x^3 - 123x^2 + 68x + 854 = 0\n";
						std::cout << "|3_ 	-653x^4 + 234x^3 - 24x^2 - 955x + 12 = 0\n";
						std::cout << "|4_ 	24x^4 + 34x^3 -345x^2 -12x + 45 = 0\n";
						std::cout << "|Faite votre choix en tapant le numero : ";
						int choixEqua = 0;
						std::cin>>choixEqua;
						std::cout << "|\n";
						if(choixEqua == 1){
							Poly4 poly4(3, 45, -24, -150, 4);
							poly4.ferrrari();
							poly4.afficherRacines();
						}else if(choixEqua == 2){
							Poly4 poly4(2567, -248, -123, 68, 854);
							poly4.ferrrari();
							poly4.afficherRacines();
						}else if(choixEqua == 3){
							Poly4 poly4(-653, 234, -24, -955, 12);
							poly4.ferrrari();
							poly4.afficherRacines();
						}else if(choixEqua == 4){
							Poly4 poly4(24, 34, -345, -12, 45);
							poly4.ferrrari();
							poly4.afficherRacines();
						}
					}
					 
				}
				else if (choix2 == "2") { //Méthode de Berntein
					std::cout << "|1_Resoudre un polynome \n";
					std::cout << "|2_Exemples \n";
					std::cout << "|Faite votre choix en tapant le numero : ";

					int choix3 =0;
					std::cin >> choix3;
					std::cout << "|\n";
					if(choix3 == 1){
						std::cout << "\n|Donner l'equation :\n";
						std::cout << "|aX^4 + bX^3+ cX^2 +dX +e\n";
						double a, b, c, d, e = 0;
						std::cout << "|a : ";
						std::cin >> a;

						while (a == 0) {
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
						Bernstein poly(a, b, c, d, e);
						poly.root(0.0000001);
						poly.showracine();
					}else if(choix3 == 2){
						std::cout << "|Choissisez l'une des equations suivantes :\n";
						std::cout << "|1_ 	3x^4 + 45x^3 - 24x^2 - 150x + 4 = 0\n";
						std::cout << "|2_ 	2567x^4 - 248x^3 - 123x^2 + 68x + 854 = 0\n";
						std::cout << "|3_ 	-653x^4 + 234x^3 - 24x^2 - 955x + 12 = 0\n";
						std::cout << "|4_ 	24x^4 + 34x^3 -345x^2 -12x + 45 = 0\n";
						std::cout << "|Faite votre choix en tapant le numero : ";

						int choixEqua = 0;
						std::cin>>choixEqua;
						std::cout << "|\n";
						if(choixEqua == 1){
							Bernstein poly(3, 45, -24, -150, 4);
							poly.root(0.0000001);
							poly.showracine();
						}else if(choixEqua == 2){
							Bernstein poly(2567, -248, -123, 68, 854);
							poly.root(0.0000001);
							poly.showracine();
						}else if(choixEqua == 3){
							Bernstein poly(-653, 234, -24, -955, 12);
							poly.root(0.0000001);
							poly.showracine();
						}else if(choixEqua == 4){
							Bernstein poly(24, 34, -345, -12, 45);
							poly.root(0.0000001);
							poly.showracine();
						}
					}
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
			std::cout << "|\n";
			if (choix2 != "4") {

				if (choix2 == "1") { // Méthode Newton
					std::cout << "|1_Resoudre un polynome \n";
					std::cout << "|2_Exemples \n";
					std::cout << "|Faite votre choix en tapant le numero : ";

					int choix3 =0;
					std::cin >> choix3;
					std::cout << "|\n";
					if(choix3 == 1){
						std::cout << "\n|Donner l'equation :\n";
						std::cout << "|aX^5 + bX^4+ cX^3 +dX^2 +eX +f\n";
						double a, b, c, d, e,f = 0;
						std::cout << "|a : ";
						std::cin >> a;

						while (a == 0) {
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
						Poly5 p5(a,b,c,d,e,f);
						p5.solve();
						p5.afficherRacines();
					}else if(choix3 == 2){
						std::cout << "|Choissisez l'une des equations suivantes :\n";
						std::cout << "|1_ 	24x^5 - 67x^4 + 45x^3 - 24x^2 - 150x + 4 = 0\n";
						std::cout << "|2_ 	-567x^5 + 237x^4 - 248x^3 - 153x^2 + 68x + 54 = 0\n";
						std::cout << "|3_ 	765x^5 - 653x^4 + 234x^3 + 24x^2 - 955x + 12 = 0\n";
						std::cout << "|4_ 	-2x^5 + 24x^4 + 34x^3 -345x^2 -182x + 45 = 0\n";
						std::cout << "|Faite votre choix en tapant le numero : ";

						int choixEqua = 0;
						std::cin>>choixEqua;
						std::cout << "|\n";
						if(choixEqua == 1){
							Poly5 p5(24,-67,45,-24,-150,4);
							p5.solve();
							p5.afficherRacines();
						}else if(choixEqua == 2){
							Poly5 p5(-567,237,-248,-153,68,54);
							p5.solve();
							p5.afficherRacines();
						}else if(choixEqua == 3){
							Poly5 p5(765,-653,234,24,-955,12);
							p5.solve();
							p5.afficherRacines();
						}else if(choixEqua == 4){
							Poly5 p5(-2,24,34,-345,-182,45);
							p5.solve();
							p5.afficherRacines();
						}
					}

					
				}else if(choix2 == "2") {//Méthode de Bernstein
					std::cout << "|1_Resoudre un polynome \n";
					std::cout << "|2_Exemples \n";
					std::cout << "|Faite votre choix en tapant le numero : ";

					int choix3 =0;
					std::cin >> choix3;
					std::cout << "|\n";
					if(choix3 == 1){
						std::cout << "\n|Donner l'equation :\n";
						std::cout << "|aX^5 + bX^4+ cX^3 +dX^2 +eX +f\n";
						double a, b, c, d, e,f = 0;
						std::cout << "|a : ";
						std::cin >> a;

						while (a == 0) {
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
						Bernstein poly(a, b, c, d, e,f);
						poly.root(0.0000001);
						poly.showracine();
					}else if(choix3 == 2){
						std::cout << "|Choissisez l'une des equations suivantes :\n";
						std::cout << "|1_ 	24x^5 - 67x^4 + 45x^3 - 24x^2 - 150x + 4 = 0\n";
						std::cout << "|2_ 	-567x^5 + 237x^4 - 248x^3 - 153x^2 + 68x + 54 = 0\n";
						std::cout << "|3_ 	765x^5 - 653x^4 + 234x^3 + 24x^2 - 955x + 12 = 0\n";
						std::cout << "|4_ 	-2x^5 + 24x^4 + 34x^3 -345x^2 -182x + 45 = 0\n";
						std::cout << "|Faite votre choix en tapant le numero : ";

						int choixEqua = 0;
						std::cin>>choixEqua;
						std::cout << "|\n";
						if(choixEqua == 1){
							Bernstein poly(24,-67,45,-24,-150,4);
							poly.root(0.0000001);
							poly.showracine();
						}else if(choixEqua == 2){
							Bernstein poly(-567,237,-248,-153,68,54);
							poly.root(0.0000001);
							poly.showracine();
						}else if(choixEqua == 3){
							Bernstein poly(765,-653,234,24,-955,12);
							poly.root(0.0000001);
							poly.showracine();
						}else if(choixEqua == 4){
							Bernstein poly(-2,24,34,-345,-182,45);
							poly.root(0.0000001);
							poly.showracine();
						}
					}
				}
				else{
					choix2 = "0";//retour
				}
			}
			else {
				choix = "0"; //retour
			}
		}
		
	}
	
	return 0;
}


