#include <bits/stdc++.h>
using namespace std;

// 1.Brute Force O(n3)
void colFill(int j, vector<vector<int>> &matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        if (matrix[i][j] != 0)
            matrix[i][j] = 'a';
    }
}
void rowFill(int k, vector<vector<int>> &matrix)
{
    for (int i = 0; i < matrix[0].size(); i++)
    {
        if (matrix[k][i] != 0)
            matrix[k][i] = 'a';
    }
}
void setZeroes1(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                colFill(j, matrix);
                rowFill(i, matrix);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] == 'a')
                matrix[i][j] = 0;
        }
    }
}

// Better O(M*N) O(M+N)
void setZeroes2(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> rowTrack(m);
    vector<int> colTrack(n);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                colTrack[j] = 1;
                rowTrack[i] = 1;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (rowTrack[i] == 1 || colTrack[j] == 1)
            {
                matrix[i][j] = 0;
            }
        }
    }
}

// Optimal O(m*n) S(1)
void setZeroes3(vector<vector<int>> &matrix)
{ // Optimizing the Bette approach inside the Matrix itself
    int m = matrix.size();
    int n = matrix[0].size();
    int col0 = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                if (j != 0)
                    matrix[0][j] = 0;
                else
                    col0 = 0;
            }
        }
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }
    if (matrix[0][0] == 0)
    {
        for (int i = 1; i < n; i++)
        {
            matrix[0][i] = 0;
        }
    }

    if (col0 == 0)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[j][0] = 0;
        }
    }
}
int main()
{

    vector<vector<int>> m = {{0, 1, 2, 0},
                             {3, 4, 5, 2},
                             {1, 3, 1, 5}};
    setZeroes3(m);
    for (int i = 0; i < m.size(); i++)
    {
        for (int j = 0; j < m[0].size(); j++)
        {
            cout << m[i][j] << endl;
        }
    }
    return 0;
}