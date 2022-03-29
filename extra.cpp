#include "extra.h"

double LinearEquationSystem::calcAlgebraicComplement(const double matrix[3][3], int row, int col)
{
  std::cout << "--------------Calculating algebraic complement" << "[" << row+1 << "]"
      << "[" << col+1 << "]" << "--------" << std::endl;

  double minor2d[4], algebraicComplement;

  std::cout << "--------------Calculating minor" << "[" << row+1 << "]"
      << "[" << col+1 << "]" << "-----------------------" << std::endl;

  std::cout << "Minor: " << std::endl;
  int i{0};

  for(int j{0}; j < 3; j++)
  {
    for(int k{0}; k < 3; k++)
    {
      if(j != row && k != col)
      {
        minor2d[i] = matrix[j][k];
        std::cout << minor2d[i] << " ";
        if((i+1)%2 == 0)
        {
          std::cout << std::endl;
        }
        i++;
      }
    }
  }

  std::cout << std::endl;

  algebraicComplement = pow(-1, row+col) * ((minor2d[0] * minor2d[3] - minor2d[1] * minor2d[2]));
  std::cout << "Algebraic complement[" << row+1 << "][" << col+1 << "]:" << algebraicComplement << std::endl;
  return algebraicComplement;
}

double LinearEquationSystem::calcDeterminant(const double matrix[3][3])
{
  std::cout << "--------------Calculating determinant-----------------------" << std::endl;

  double det;

  for(int i{0}; i < 3; i++)
  {
    det += matrix[0][i] * calcAlgebraicComplement(matrix, 0, i);
  }

  std::cout << "Determinant: " << det << std::endl;

  return det;
}

void LinearEquationSystem::calcInverseMatrix()
{
  std::cout << "--------------Calculating inverse matrix A------------------" << std::endl;

  for(int i{0}; i < 3; i++)
  {
    for(int j{0}; j < 3; j++)
    {
      inverseAMatrix[i][j] = calcAlgebraicComplement(aMatrix, j, i)/determinant;
    }
  }

  std::cout << "Inverse Matrix: " << std::endl;

  for(int i{0}; i < 3; i++)
  {
    for(int j{0}; j < 3; j++)
    {
      std::cout << inverseAMatrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

void LinearEquationSystem::inverseMatrixMethod()
{
  std::cout << "**************Inverse Matrix Method ************************" << std::endl;

  determinant = calcDeterminant(aMatrix);
  if(determinant == 0)
  {
    std::cout << "~This Linear Equation System is incompatible~" << std::endl;
    return;
  }
  calcInverseMatrix();

  std::cout << "--------------Multiplying matrix A^(-1) and B---------------" << std::endl;

  std::cout << "Matrix X: " << std::endl;

  for(int i{0}; i < 3; i++)
  {
    for(int j{0}; j < 3; j++)
    {
      xMatrix[i][0] += inverseAMatrix[i][j] * bMatrix[j][0];
    }
    std::cout << xMatrix[i][0] << std::endl;
  }
}

void LinearEquationSystem::printSystem()
{
  std::cout << "--------------Linear Equation System------------------------" << std::endl;
  for(int i{0}; i < 3; i++)
  {
    for(int j{0}; j < 3; j++)
    {
      if(aMatrix[i][j] > 0)
      {
        std::cout << " + " << aMatrix[i][j] << "x[" << j + 1 << "]" << " ";
      } else if(aMatrix[i][j] < 0)
      {
        std::cout << " - " << (-1) * aMatrix[i][j] << "x[" << j + 1 << "]" << " ";
      }
    }
    std::cout << "= " << bMatrix[i][0] << std::endl;
  }
}

void LinearEquationSystem::calcXxBMatrix(double (*XxBMatrix)[3][3], int num)
{
  std::cout << "--------------Calculating matrixA[" << num+1 << "]------------------------" << std::endl;

  std::cout << "MatrixA[" << num+1 << "]" << std::endl;

  for(int i{0}; i < 3; i++)
  {
    for(int j{0}; j < 3; j++)
    {
      if(j == num)
      {
        (*XxBMatrix)[i][j] = bMatrix[i][0];
      } else
      {
        (*XxBMatrix)[i][j] = aMatrix[i][j];
      }

      std::cout << (*XxBMatrix)[i][j] << " ";
    }
    std::cout << std::endl;
  }

}

void LinearEquationSystem::CramersMethod()
{
  std::cout << "**************Cramer's Method*******************************" << std::endl;

  double AMatrix[3][3], detA;

  determinant = calcDeterminant(aMatrix);

  if(determinant == 0)
  {
    std::cout << "~This Linear Equation System is incompatible~" << std::endl;
    return;
  }

  for(int i{0}; i < 3; i++)
  {
    calcXxBMatrix(&AMatrix, i);
    detA = calcDeterminant(AMatrix);
    xMatrix[i][0] = detA/determinant;
    std::cout << "X[" << i+1 << "] = " << xMatrix[i][0] << std::endl;
  }

  std::cout << std::endl;

  for(int i{0}; i < 3; i++)
  {
    std::cout << "X[" << i+1 << "] = " << xMatrix[i][0] << " ";
  }

  std::cout << std::endl;
}