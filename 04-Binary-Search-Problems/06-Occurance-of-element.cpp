#include <bits/stdc++.h>
using namespace std;
int count(vector<int> &arr, int n, int x)
{
    // Write Your Code Here
    int low = 0, high = n - 1;
    int first = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == x)
        {
            first = mid;
            high = mid - 1;
        }
        else if (arr[mid] > x)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    if (first == -1)
        return 0;
    low = 0, high = n - 1;
    int last = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == x)
        {
            last = mid;
            low = mid + 1;
        }
        else if (arr[mid] > x)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return (last - first + 1);
}

int main()
{
    vector<int> v = {1,
                     1,
                     1,
                     2,
                     2,
                     3,
                     3};
    int ans = count(v, v.size(), 3);
    cout << ans;

    return 0;
}