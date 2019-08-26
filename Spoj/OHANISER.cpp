#include <bits/stdc++.h>
using namespace std;
int a[5010],b[5010];
#define ll long long
ll m=1000000007;
ll me(ll a,ll b,ll m)
{
    ll ans=1;
    while(b)
    {
        if(b&1)
        {
            ans=(ans%m*a%m)%m;
        }
        a=(a%m*a%m)%m;
        b=b/2;
    }
    return ans;
}
int main()
{
    int t;
    cin>>t;
    int c=1;
    while(t--)
    {
        ll n;
        cin>>n;
        cout<<"Case "<<c++<<": ";
        if(n==1)
            cout<<"1\n";
        else
        cout<<((n+1)%m*(me(2,n-2,m)%m))%m<<"\n";
    }
    return 0;
}
