#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
ll n,k,d;
ll dp[110][110];
ll m=1000000007;
ll me(ll a,ll b)
{
    ll ans=1;
    while(b>0)
    {
        if(b%2==1)
        {
            ans = (ans*a);
            ans%=m;
        }
        b=b/2;
        a=(a*a)%m;
    }
    return ans;
}
int main()
{
   cin>>n;
   ll ans=me(3,3*n)-me(7,n);
   ans=(ans+m)%m;
   cout<<ans<<"\n";
}