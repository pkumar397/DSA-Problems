#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum1(vector<int> &nums)
{
    // Brute Force
    set<vector<int>> s;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            for (int k = j + 1; k < nums.size(); k++)
            {
                if ((nums[i] + nums[j] + nums[k]) == 0)
                {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    sort(temp.begin(), temp.end());
                    s.insert(temp);
                }
            }
        }
    }
    return vector<vector<int>>(s.begin(), s.end());
}

vector<vector<int>> threeSum2(vector<int> &nums)
{
    // Better Optimizing the Brute Force itself
    set<vector<int>> s;
    for (int i = 0; i < nums.size(); i++)
    {
        set<int> temp;
        for (int j = i + 1; j < nums.size(); j++)
        {
            int third = -(nums[i] + nums[j]);
            if (temp.find(third) != temp.end())
            {
                vector<int> t = {nums[i], nums[j], third};
                sort(t.begin(), t.end());
                s.insert(t);
            }
            temp.insert(nums[j]);
        }
    }
    return vector<vector<int>>(s.begin(), s.end());
}

vector<vector<int>> threeSum3(vector<int> &nums)
{
    // Optimized using sorting
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    for (int i = 0; i < nums.size() - 2; i++)
    {
        if (i != 0 && nums[i] == nums[i - 1])
            continue;
        int l = i + 1, r = nums.size() - 1;
        while (l < r)
        {
            int sum = nums[i] + nums[l] + nums[r];
            if (sum == 0)
            {
                vector<int> temp = {nums[i], nums[l], nums[r]};
                ans.push_back(temp);
                l++, r--;
                while (l < r && nums[l] == nums[l - 1])
                    l++;
                while (l < r && nums[r] == nums[r + 1])
                    r--;
            }
            else if (sum < 0)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> v = {-1, -1, -1, -1, -2, -2, -2, -2, 0, 0, 0, 0, 1, 1, 1, 1};
    vector<vector<int>> ans = threeSum3(v);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << endl;
        }
        cout << "----" << endl;
    }
    return 0;
}