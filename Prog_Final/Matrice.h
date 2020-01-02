#ifndef MATRICE_H
#define MATRICE_H

#include "iostream"
#include "vector"

class Matrice
{

private:
    int m_colonne;                          //n  //nombre de colonne de la matrice
    int m_ligne;                            //m //nombre de ligne de la matrice
    std::vector<std::vector<double>> m_mat; // les cases de la matrice

public:
    void showmat() const;                            //affiche la matrice
    void setmat(int m, int n, double val);           // definie une valeur dans une case de la matrice
    double getcell(int m, int n) const;              // renvoie une valeur dans une case de la matrice
    std::vector<std::vector<double>> getmat() const; //renvoie le tableau qui représente la matrice
    int getligne() const;                            // renvoie le nombre de ligne
    int getcolonne() const;                          // renvoie le nombre de colonne

    Matrice(int m = 0, int n = 0); //constructeur
};

Matrice factor(double fact, Matrice const &mat1);           //fact*mat1 //surchage d'oppérateur
Matrice multiply(Matrice const &mat1, Matrice const &mat2); //mat1*mat2 //surchage d'oppérateur

Matrice operator*(double fact, Matrice const &mat1); //fact*mat1 //surchage d'oppérateur
Matrice operator*(Matrice const &mat1, double fact); //mat1*fact //surchage d'oppérateur

Matrice operator*(Matrice const &mat1, Matrice const &mat2); //mat1 * mat2 //surchage d'oppérateur
Matrice creationmatriceinf(Matrice matrice, int k, int i);   // crée la matrice [m-1 , n-1] pour calculer le determinant
double determinant(Matrice matrice);                         //renvoie le determinant de la Matrice
double adjugate(Matrice matrice, int m, int n);              //renvoie la valeur de la matrice
Matrice inv(Matrice matrice);                                //inverse la matrice adjointe
Matrice transpose(Matrice matrice);                          //fait la transposé de la comatrice

#endif
