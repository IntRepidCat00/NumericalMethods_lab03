#ifndef LAB03_EXTRA_H
#define LAB03_EXTRA_H
#include <cmath>
#include <iostream>

class LinearEquationSystem
{
private:
    double xMatrix[3][1]
            {
                    {0},
                    {0},
                    {0}
            };
    double aMatrix[3][3]
            {
                    {0.34, 0.71, 0.63},
                    {0.71, -0.65, -0.18},
                    {1.17, -2.35, 0.75}
            };
    double bMatrix[3][1]
            {
                    {2.08},
                    {0.17},
                    {1.28}
            };
    double inverseAMatrix[3][3]
            {
                    {0, 0, 0},
                    {0, 0, 0},
                    {0, 0, 0}
            };
    double determinant{0};

    double calcDeterminant(const double matrix[3][3]);
    double calcAlgebraicComplement(const double matrix[3][3], int row, int col);
    void calcInverseMatrix();
    void calcXxBMatrix(double (*XxBMatrix)[3][3], int num);
public:
    void printSystem();
    void inverseMatrixMethod();
    void CramersMethod();
};

#endif //LAB03_EXTRA_H
