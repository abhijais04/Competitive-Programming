#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
set<ll> s;
int dp[100010];
int main()
{
    int n;
    int m;
    cin>>n;
    cin>>m;
    ll a[n];
    for(int i=0;i<n;i++)
    {
        ll x;
        cin>>a[i];
        //dp[i]=(ll)s.size();
    }
    for(int i=n-1;i>=0;i--)
    {
        s.insert(a[i]);
        dp[i]=(ll)s.size();
    }
    while(m--)
    {
        int l;
        cin>>l;
        cout<<dp[l-1]<<"\n";
    }
}