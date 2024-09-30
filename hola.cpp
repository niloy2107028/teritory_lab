#include <iostream>
#include <vector>
#include <cmath>

const double epsilon = 1e-9;

using namespace std;

void printing_matrix(vector<vector<double>> matrix)
{
    cout << "printing matrix :" << endl;
    for (const auto row : matrix)
    {
        for (double element : row)
        {
            cout << element << " ";
        }
        cout << endl;
    }
}

void printing_inverse_matrix(vector<vector<double>> matrix)
{
    cout << "printing matrix :" << endl;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = matrix.size(); j < matrix.size() * 2; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void gauss_eli(vector<vector<double>> &matrix)
{
    int size = matrix.size();

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (abs(matrix[i][i]) < epsilon)
            {
                cout << "Error! Near zero pivot element at row " << i << " (element: " << matrix[i][i] << ")." << endl;
                exit(EXIT_FAILURE);
            }

            double factor = matrix[j][i] / matrix[i][i];

            for (int k = i; k < size * 2; k++)
            {
                matrix[j][k] -= factor * matrix[i][k];
            }
        }
    }
}

void jordan_eli(vector<vector<double>> &matrix)
{
    int size = matrix.size();

    for (int i = size - 1; i > -1; i--)
    {
        for (int j = i - 1; j > -1; j--)
        {
            if (abs(matrix[i][i]) < epsilon)
            {
                cout << "Error! Near zero pivot element at row " << i << " (element: " << matrix[i][i] << ")." << endl;
                exit(EXIT_FAILURE);
            }

            double factor = matrix[j][i] / matrix[i][i];

            for (int k = size * 2 - 1; k > -1; k--)
            {
                matrix[j][k] -= factor * matrix[i][k];
            }
        }
    }
}

void row_eche(vector<vector<double>> &matrix)
{
    int size = matrix.size();
    for (int i = 0; i < size; i++)
    {

        double diag = matrix[i][i];
        if (abs(diag) > epsilon)
        {
            for (int j = 0; j < size * 2; j++)
            {
                matrix[i][j] /= diag;
            }
        }
    }
}

void put_identity(vector<vector<double>> &matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = matrix.size(); j < matrix.size() * 2; j++, i++)
        {
            matrix[i][j] = 1;
        }
        cout << endl;
    }
}

void inverse_matrix(vector<vector<double>> &matrix)
{
    put_identity(matrix);
    gauss_eli(matrix);
    jordan_eli(matrix);
    row_eche(matrix);
}

/*

3
1 1 -1
1 -1 2
2 1 1

*/

int main()

{
    int no_of_variable = 0;
    cin >> no_of_variable;

    vector<vector<double>> matrix(no_of_variable, vector<double>(no_of_variable + no_of_variable, 0));

    for (int i = 0; i < no_of_variable; i++)
    {
        for (int j = 0; j < no_of_variable; j++)
        {
            cin >> matrix[i][j];
        }
    }

    inverse_matrix(matrix);

    printing_inverse_matrix(matrix);

    return 0;
}
