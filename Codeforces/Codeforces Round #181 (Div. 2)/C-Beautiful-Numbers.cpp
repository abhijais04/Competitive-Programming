#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll fact[1000010];
ll m=1e9+7;
ll me(ll a,ll b,ll m)
{
    ll ans=1;
    while(b>0)
    {
        if(b%2==1)
        {
            ans=(ans%m*a%m)%m;
        }
        a=(a*a)%m;
        b/=2;
    }
    return ans%m;
}
bool check(ll x,ll a,ll b)
{
    while(x>0)
    {
        int dg=x%10;
        if(dg!=a&&dg!=b)
            return false;
        x/=10;
    }
    return true;
}
ll ncr(ll n,ll r)
{
    ll fn = fact[n];
    ll tf = fact[r]*fact[n-r];
    tf=tf%m;
    tf = me(tf,m-2,m);
    fn = (tf%m*fn%m)%m;
    return fn%m;
}
int main()
{
    fact[0]=1;
    for(ll i=1;i<=1000001;i++)
    {
        fact[i]= (fact[i-1]*i)%m;
    }
    int n,a,b;
    cin>>a>>b>>n;
    if(a==b)
    {
        if(check(n*a,a,b))
        {
            cout<<"1\n";
        }
        else
            cout<<"0\n";
        return 0;
    }
    ll ans=0;
    for(ll i=0;i<=n;i++)
    {
        ll tmp = i*a + (n-i)*b;
        if(check(tmp,a,b))
        {
            ans+=ncr(n,i);
            ans%=m;
        }
    }
    cout<<ans<<"\n";
    return 0;
}