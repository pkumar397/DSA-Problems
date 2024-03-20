#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        if (ans.empty() || ans.back()[1] < intervals[i][0])
        {
            ans.push_back(intervals[i]);
        }
        else
        {
            ans.back()[1] = max(intervals[i][1], ans.back()[1]);
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> v = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> ans = merge(v);
    for (auto it : ans)
    {
        for (auto i : it)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}