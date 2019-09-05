#include <bits/stdc++.h>
using namespace std;
long long dp[2000010];
long long m=1000000007;
string str;
long long fn(long long x)
{
    long long i;
    for(i=x-1;i>=0;i--)
    {
        if(str[i]==str[x])
            return dp[i];
    }
    return 0;
}
int main()
{
    int n,i;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    int mn=0,mx=0;
    for(i=1;i<n;i++)
    {
        if(a[i]>a[mx])
            mx=i;
        if(a[i]<a[mn])
            mn=i;
    }
    int mx1=max(abs(mn-(n-1)),abs(mx-(n-1)));
    int mx2=max(mn,mx);
    cout<<max(mx1,mx2)<<"\n";

}