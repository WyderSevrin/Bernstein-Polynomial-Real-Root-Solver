#include "Matrice.h"

void Matrice::showmat() const
{
    for (int i = 0; i < m_ligne; i++)
    {
        for (int j = 0; j < m_colonne; j++)
        {
            std::cout << m_mat[i][j] << " "; //affiche toute les cases de la matrice
        }
        std::cout << "\n";
    }
}

void Matrice::setmat(int m, int n, double val) //offset de -1 pour que le code soit plus lisible
{
    if (m <= m_ligne && n <= m_colonne) //test de validité des paramètres
    {
        m_mat[m - 1][n - 1] = val; //enregistrement de la valeur
    }
    else
    {
        std::cerr << "erreur placement de valeur en dehors de la matrice";
    }
}

int Matrice::getligne() const //renvoie le nombre de ligne
{
    return m_ligne;
}

int Matrice::getcolonne() const //renvoie le nombre de colonne
{
    return m_colonne;
}

double Matrice::getcell(int m, int n) const //renvoie la valeur dans la cellule
{
    return m_mat[m][n];
}

std::vector<std::vector<double>> Matrice::getmat() const //renvoie le tableau qui represente la matrice
{
    return m_mat;
}

Matrice factor(double fact, Matrice const &mat1) //permet de multiplier une matrice et un coefficient
{
    Matrice temp(mat1.getligne(), mat1.getcolonne());
    for (int i = 0; i < mat1.getligne(); i++)
    {
        for (int j = 0; j < mat1.getcolonne(); j++)
        {
            temp.setmat(i + 1, j + 1, mat1.getcell(i, j) * fact);
        }
    }
    return temp;
}

Matrice::Matrice(int m, int n) //constructeur de la matrice
{
    m_ligne = m;
    m_colonne = n;
    m_mat.resize(m, std::vector<double>(n, 0));
}

Matrice multiply(Matrice const &mat1, Matrice const &mat2) //mat1*mat2 //permet de multiplier une matrice avec une autre
{

    if (mat1.getcolonne() == mat2.getligne()) //test de validité des 2 matrices en paramètre
    {
        Matrice temp(mat1.getligne(), mat2.getcolonne());
        double val;

        for (int i = 0; i < temp.getligne(); i++) // nombre de tour de boucle a faire
        {
            for (int j = 0; j < temp.getcolonne(); j++) // on parcourt toutes les cases de la matrice resultante
            {
                for (int k = 0; k < mat1.getcolonne(); k++)
                {
                    val = val + mat1.getcell(i, k) * mat2.getcell(k, j); //formule de calcul
                }
                temp.setmat(i + 1, j + 1, val); //assignation de la valeur à la bonne case
                val = 0;                        //reset de la valeur
            }
        }
        return temp; //renvoie la matrice qui resulte du calcul
    }
    else
    {
        std::cerr << "erreur de taille de matrice";
        return Matrice(0, 0);
    }
}

Matrice operator*(double fact, Matrice const &mat1) //surcharge d'oppérateur pour la multiplcation d'un coefficient et d'une matrice
{
    return factor(fact, mat1);
}
Matrice operator*(Matrice const &mat1, double fact) //surcharge d'oppérateur pour la multiplcation d'une matrice et d'un coefficient
{
    return factor(fact, mat1);
}

Matrice operator*(Matrice const &mat1, Matrice const &mat2) //surcharge d'oppérateur pour la multiplcation d'une matrice et d'une matrice
{
    return multiply(mat1, mat2);
}

Matrice creationmatriceinf(Matrice matrice, int k, int i) //creation de la matrice [m-1 , n-1] pour calculer le determinant
{

    Matrice nvmat(matrice.getligne() - 1, matrice.getcolonne() - 1);

    int compteurm = 0;
    for (int m = 0; m < matrice.getligne(); m++)
    {

        int compteurn = 0;
        if (m != k)
        {
            for (int n = 0; n < matrice.getcolonne(); n++)
            {
                if (n != i)
                {
                    nvmat.setmat(compteurm + 1, compteurn + 1, matrice.getcell(m, n));
                    compteurn++;
                }
            }
            compteurm++;
        }
    }
    return nvmat;
}

double determinant(Matrice matrice) //calcul le determinant
{
    if (matrice.getligne() == 2 && matrice.getcolonne() == 2)
    {
        return ((matrice.getcell(0, 0) * matrice.getcell(1, 1)) - (matrice.getcell(1, 0) * matrice.getcell(0, 1))); //calcul du determinant d'une matrice [2,2]
    }
    else // on decompose en sous matrice jusqua pouvoir obtenir une matrice [2,2] d'ont la formule du determinant est connue
    {
        double determinantvalue = 0;
        for (int k = 0; k < matrice.getligne(); k++)
        {
            double coefficient = 0.0;

            if (k % 2 == 0) //calcul des signes en coefficient pour calculer le determinant
            {
                coefficient = 1.0;
            }
            else
            {
                coefficient = -1.0;
            }
            Matrice detmatrice = creationmatriceinf(matrice, k, 0);

            determinantvalue += matrice.getmat()[k][0] * coefficient * determinant(detmatrice);
        }
        return determinantvalue;
    }
}

double adjugate(Matrice matrice, int k, int i) // k = m ; i= n //calcul la comatrice
{
    double coefficient = 0.0;
    int exposant = k + i;

    if (exposant % 2 == 0)
    {
        coefficient = 1.0;
    }
    else
    {
        coefficient = -1.0;
    }

    Matrice adjmatrice = creationmatriceinf(matrice, k, i);

    return coefficient * determinant(adjmatrice);
}

Matrice transpose(Matrice matrice) //crée la matrice transposé
{
    Matrice transp = matrice;

    for (int m = 0; m < matrice.getligne(); m++)
    {

        for (int n = 0; n < matrice.getcolonne(); n++)
        {
            transp.setmat(m + 1, n + 1, matrice.getcell(n, m)); //inversion des valeur [m,n] = [n,m]
        }
    }

    return transp;
}

Matrice inv(Matrice matrice) // inversion de la matrice
{
    Matrice inv = matrice;
    Matrice transp = transpose(matrice); //matrice transposé

    for (int m = 0; m < matrice.getligne(); m++) // on parcourt toutes les cases de la matrice
    {

        for (int n = 0; n < matrice.getcolonne(); n++)
        {

            inv.setmat(m + 1, n + 1, adjugate(transp, m, n)); //calcul de la matrice inverse sans la division part le determinant
        }
    }
    return inv * (1 / determinant(matrice)); //renvoie la matrice inverse
}
