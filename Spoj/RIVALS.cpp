#include <bits/stdc++.h>
using namespace std;
#define ll long long
long long m=1000000007;
ll fact[2000010];
ll me(ll a,ll b,ll md)
{
    a=a%md;
    ll ans=1;
    while(b)
    {
        if(b%2==1)
        {
            ans=(ans%md*a%md)%md;
        }
        a=(a%m*a%m)%m;
        b=b/2;
    }
    return ans%md;
}
int main()
{

    fact[0]=1;
    for(int i=1;i<=2000007;i++)
        fact[i]=(fact[i-1]%m*i%m)%m;
    int t;
    cin>>t;
    while(t--)
    {
        ll x,y;
        cin>>x>>y;
        ll ans = fact[x+y];
        ll tmp=(fact[x]%m*fact[y]%m)%m;
        tmp=me(tmp,m-2,m);
        ans=(ans%m*tmp%m)%m;
        cout<<(ans+m)%m<<"\n";
    }
    return 0;
}
