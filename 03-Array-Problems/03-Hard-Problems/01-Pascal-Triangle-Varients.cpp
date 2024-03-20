// There Are Three Types of Pascal Triangle 1.) row and col given 2.) row given 3) return complete pascal triangle.

#include <bits/stdc++.h>
using namespace std;

// 1st Varient ,//   Solved using (r-1)C(c-1) ,also can be solved in shorter O(r)

int nCr(int n, int r)
{
    long long res = 1;

    // calculating nCr:
    for (int i = 0; i < r; i++)
    {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

int adjactEl(int rowNum, int colNum)
{
    return nCr(rowNum - 1, colNum - 1);
}

// Print all elements of rowNum
void pascalTriangle(int n)
{
    long long ans = 1;
    cout << ans << " "; // printing 1st element

    // Printing the rest of the part:
    for (int i = 1; i < n; i++)
    {
        ans = ans * (n - i);
        ans = ans / i;
        cout << ans << " ";
    }
    cout << endl;
}

// Complete Pascal triangle
vector<int> generateRow(int row)
{
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1); // inserting the 1st element

    // calculate the rest of the elements:
    for (int col = 1; col < row; col++)
    {
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;
}

vector<vector<int>> pascalTriangle2(int n)
{
    vector<vector<int>> ans;

    // store the entire pascal's triangle:
    for (int row = 1; row <= n; row++)
    {
        ans.push_back(generateRow(row));
    }
    return ans;
}

int main()
{
    // int r = 4, c = 3;
    // cout << adjactEl(r, c);
    int n = 3;
    vector<vector<int>> ans = pascalTriangle2(n);
    return 0;
}