#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector<int> a)
{
    // Write your code here
    // Brute Force
    // int repeated=-1,missing=-1;
    // for(int i=1;i<=a.size();i++){
    //     int cnt=0;
    //     for(int j=0;j<a.size();j++){
    //         if(a[j]==i) cnt++;
    //     }
    //     if(cnt==2) repeated=i;
    //     if(cnt==0) missing=i;

    //     if(repeated!=-1 && missing!=-1) break;
    // }
    // return {repeated,missing};

    // Better Using HashMap
    //    int n=a.size();
    //    int hash[n+1]={0};
    //     for(int i=0;i<a.size();i++){
    //         hash[a[i]]++;
    //     }

    //     int repeated=-1,missing=-1;
    //     for(int i=1;i<=a.size();i++){
    //        if(hash[i]==2) repeated=i;
    //        else if(hash[i]==0) missing=i;
    //        if(missing!=-1 && repeated!=-1) break;
    //     }
    //     return {repeated,missing};

    // Optimal Using Arthemetics (1st Apprach)
    long long n = a.size();
    long long SN = n * (n + 1) / 2;
    long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;

    long long S = 0, S2 = 0;
    for (int i = 0; i < n; i++)
    {
        S += a[i];
        S2 += (long long)a[i] * (long long)a[i];
    }

    long long val1 = S - SN;   // X-Y=S-SN
    long long val2 = S2 - S2N; // X2N-Y2N=S2-S2N

    val2 = val2 / val1; // X2N-Y2N=X+Y * X-Y
    long long x = (val1 + val2) / 2;
    long long y = (x - val1);
    return {int(x), int(y)};

    // Optimal Second Apporoach
}

int main()
{
    vector<int> v = {2, 1, 1, 3, 4};
    vector<int> ans = findMissingRepeatingNumbers(v);
    cout << "Repeating Number:" << ans[0] << ", Missing Number:" << ans[1];
    return 0;
}