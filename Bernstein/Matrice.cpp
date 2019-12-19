#include "matrice.h"

void Matrice::showmat() const
{
    for (int i = 0; i < m_line; i++)
    {
        for (int j = 0; j < m_column; j++)
        {
            std::cout << m_mat[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void Matrice::setmat(int m, int n, double val) //offset de -1 pour que le code soit plus lisible 1=1 si pas offset 0=1
{
    if (m <= m_line && n <= m_column)
    {
        m_mat[m - 1][n - 1] = val;
    }
    else
    {
        std::cerr << "erreur placement de valeur en dehors de la matrice";
    }
}

int Matrice::getline() const
{
    return m_line;
}

int Matrice::getcolumn() const
{
    return m_column;
}

double Matrice::getcell(int m, int n) const
{
    return m_mat[m][n];
}

std::vector<std::vector<double>> Matrice::getmat() const
{
    return m_mat;
}

Matrice factor(double fact, Matrice const &mat1)
{
    Matrice temp(mat1.getline(), mat1.getcolumn());
    for (int i = 0; i < mat1.getline(); i++)
    {
        for (int j = 0; j < mat1.getcolumn(); j++)
        {
            temp.setmat(i + 1, j + 1, mat1.getcell(i, j) * fact);
        }
    }
    return temp;
}

Matrice::Matrice(int m, int n)
{
    m_line = m;
    m_column = n;
    m_mat.resize(m, std::vector<double>(n, 0));
}

Matrice multiply(Matrice const &mat1, Matrice const &mat2) //mat1*mat2
{

    if (mat1.getcolumn() == mat2.getline())
    {
        Matrice temp(mat1.getline(), mat2.getcolumn());
        double val;

        for (int i = 0; i < temp.getline(); i++)
        {
            for (int j = 0; j < temp.getcolumn(); j++)
            {
                for (int k = 0; k < mat1.getcolumn(); k++)
                {
                    val = val + mat1.getcell(i, k) * mat2.getcell(k, j);
                }
                temp.setmat(i + 1, j + 1, val); // faire les sommes avec des boucles
                val = 0;
            }
        }
        return temp;
    }
    else
    {
        std::cerr << "erreur de taille de matrice";
        return Matrice(0, 0);
    }
}

Matrice operator*(double fact, Matrice const &mat1)
{
    return factor(fact, mat1);
}
Matrice operator*(Matrice const &mat1, double fact)
{
    return factor(fact, mat1);
}

Matrice operator*(Matrice const &mat1, Matrice const &mat2)
{
    return multiply(mat1, mat2);
}
