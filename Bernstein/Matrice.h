#ifndef MATRICE_H
#define MATRICE_H

#include "iostream"
#include "vector"

class Matrice
{

private:
    int m_column; //n
    int m_line;   //m
    std::vector<std::vector<double>> m_mat;

public:
    void showmat() const;
    void setmat(int m, int n, double val);
    double getcell(int m, int n) const;
    std::vector<std::vector<double>> getmat() const;
    int getline() const;
    int getcolumn() const;

    Matrice(int m = 0, int n = 0);
};

Matrice factor(double fact, Matrice const &mat1);           //fact*mat1
Matrice multiply(Matrice const &mat1, Matrice const &mat2); //mat1*mat2

Matrice operator*(double fact, Matrice const &mat1); //fact*mat1
Matrice operator*(Matrice const &mat1, double fact); //mat1*fact

Matrice operator*(Matrice const &mat1, Matrice const &mat2); //mat1 * mat2

#endif