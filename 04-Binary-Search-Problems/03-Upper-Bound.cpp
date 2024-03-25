#include <bits/stdc++.h>;
using namespace std;
int upperBound(vector<int> &arr, int x, int n)
{
    // arr[i]>x;least index.
    int low = 0, high = n - 1, ans = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> v = {1, 3, 4, 5, 7, 9, 10};
    int x = 8;
    int ans = upperBound(v, v.size(), x);
    cout << ans;
    return 0;
}