#include <bits/stdc++.h>
using namespace std;
// 1.Brute Force O(n2) O(n2)
void rotate1(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    vector<vector<int>> ans(m, vector<int>(m, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ans[j][m - 1 - i] = matrix[i][j]; // Via observation
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[i][j] = ans[i][j];
        }
    }
}

// Optimal O(n2) S(1)
void rotate2(vector<vector<int>> &matrix)
{
    // First observation is that col is row but in reversed order.
    int m = matrix.size();
    for (int i = 0; i <= m - 2; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for (int i = 0; i < m; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main()
{
    vector<vector<int>> v={{1,2,3},{4,5,6},{7,8,9}};
    rotate2(v);
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[0].size();j++){
          cout<<v[i][j]<<endl;
        }
    }
}