#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
int main()
{
    //while(1)
    {

    ll n;
    cin>>n;
    ll ans=0;
    ll pre=0;
    for(ll i=1;i<=n;i++)
    {
        ans+=(n-i)*i;
        ans++;
    }
    cout<<ans<<"\n";
    }
}