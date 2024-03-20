#include <bits/stdc++.h>
using namespace std;

// Only One Way to solve this
vector<int> spiralOrder1(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> ans;
    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;
    int direction = 0;
    while (top <= bottom && left <= right)
    {
        if (direction == 0)
        {
            for (int i = left; i <= right; i++)
                ans.push_back(matrix[top][i]);
            top++;
        }

        if (direction == 1)
        {
            for (int i = top; i <= bottom; i++)
                ans.push_back(matrix[i][right]);
            right--;
        }

        if (direction == 2)
        {
            for (int i = right; i >= left; i--)
                ans.push_back(matrix[bottom][i]);
            bottom--;
        }

        if (direction == 3)
        {
            for (int i = bottom; i >= top; i--)
                ans.push_back(matrix[i][left]);
            left++;
        }

        direction = (direction + 1) % 4;
    }
    return ans;
}

int main()
{
    vector<vector<int>> v = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> ans = spiralOrder1(v);
    for (auto it : ans)
        cout << it;
    return 0;
}