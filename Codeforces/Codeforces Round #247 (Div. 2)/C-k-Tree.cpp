#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
ll n,k,d;
ll dp[110][110];
ll m=1000000007;
ll fn(ll x,ll tmp)
{

    if(x<0)
        return 0;
    if(x==tmp)
        return 1;
    if(x<tmp)
        return 0;
    //cout<<x<<" "<<tmp<<"\n";
    if(dp[x][tmp]!=-1)
        return dp[x][tmp];
       // cout<<x<<" "<<tmp<<"\n";
    if(x==0)
    {
        if(tmp==0)
            return 1;
        return 0;
    }
    //cout<<x<<" "<<tmp<<"\n";
    ll ans=0;
    for(ll i=1;i<=k;i++)
    {
        if(i<tmp)
        ans=ans+fn(x-i,tmp);
        else
            ans=ans+fn(x-i,0);
        ans%=m;
    }
    return dp[x][tmp]=ans;
}
int main()
{
   cin>>n>>k>>d;
   for(ll i=0;i<=100;i++)
   {
       for(ll j=0;j<=100;j++)
        dp[i][j]=-1;
   }
   cout<<fn(n,d)<<"\n";
}