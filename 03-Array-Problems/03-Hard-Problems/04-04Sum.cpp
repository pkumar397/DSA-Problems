#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> fourSum1(vector<int> &nums, int target)
{
    // // Brute Force
    int n = nums.size();
    set<vector<int>> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                for (int l = k + 1; l < n; l++)
                {
                    long long sum = nums[i] + nums[j] + nums[k] + nums[l];
                    if (sum == target)
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k],
                                            nums[l]};
                        sort(temp.begin(), temp.end());
                        ans.insert(temp);
                    }
                }
            }
        }
    }
    return vector<vector<int>>(ans.begin(), ans.end());
}

vector<vector<int>> fourSum2(vector<int> &nums, int target)
{
    // Better
    int n = nums.size();
    set<vector<int>> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            set<long long> hashSet;
            for (int k = j + 1; k < n; k++)
            {
                long long sum = nums[i] + nums[j];
                sum += nums[k];
                int req = target - sum;
                if (hashSet.find(req) != hashSet.end())
                {
                    vector<int> temp = {nums[i], nums[j], nums[k], int(req)};
                    sort(temp.begin(), temp.end());
                    ans.insert(temp);
                }
                hashSet.insert((nums[k]));
            }
        }
    }
    return vector<vector<int>>(ans.begin(), ans.end());
}
vector<vector<int>> fourSum3(vector<int> &nums, int target)
{
    // Optimal
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        for (int j = i + 1; j < n; j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;
            int k = j + 1, l = n - 1;
            while (k < l)
            {
                long long sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                sum += nums[l];
                if (sum == target)
                {
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(temp);
                    k++, l--;
                    while (k < l && nums[k] == nums[k - 1])
                        k++;
                    while (k < l && nums[l] == nums[l + 1])
                        l--;
                }
                else if (sum > target)
                    l--;
                else
                    k++;
            }
        }
    }
    return ans;
}
int main()
{
    vector<int> v = {1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5};
    int target = 8;
    vector<vector<int>> ans = fourSum3(v, target);
    for (auto it : ans)
    {
        for (auto i : it)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}