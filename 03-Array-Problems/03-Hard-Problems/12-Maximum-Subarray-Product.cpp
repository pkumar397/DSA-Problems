#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int> &nums)
{
    // Brute Force
    //   int maxi=INT_MIN;
    //   for(int i=0;i<nums.size();i++){
    //         int product=1;
    //         for(int j=i;j<nums.size();j++){
    //             product*=nums[j];
    //         maxi=max(product,maxi);
    //         }
    //     }
    //     return maxi;

    // Optimal Way:
    int suffix = 1;
    int prefix = 1;
    int maxi = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        if (prefix == 0)
            prefix = 1;
        if (suffix == 0)
            suffix = 1;
        prefix = prefix * nums[i];
        suffix = suffix * nums[nums.size() - 1 - i];
        maxi = max(maxi, prefix);
        maxi = max(maxi, suffix);
    }
    return maxi;
}
int main()
{
    vector<int> v = {-2, 1, 0, 4, -1};
    cout << maxProduct(v);
    return 0;
}