#include <bits/stdc++.h>
using namespace std;
pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x)
{
    // Floor ,greatest element with a[i]<=x;
    int floor = -1, ceil = -1;
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (a[mid] <= x)
        {
            floor = a[mid];
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    // Ceil ,smallest element with a[i]>=x;
    low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (a[mid] >= x)
        {
            ceil = a[mid];
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return {floor, ceil};
}

int main()
{
    vector<int> v = {1, 3, 4, 8, 8, 10};
    pair<int, int> ans = getFloorAndCeil(v, v.size(), 5);
    cout << ans.first << " " << ans.second;
    return 0;
}