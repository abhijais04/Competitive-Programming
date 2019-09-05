#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define ll long long
#define mp make_pair
#define pp pair<ll,ll>
int main()
{
	ll n,b,d;
	cin>>n>>b>>d;
    ll a[n];
    ll i;
    for(i=0;i<n;i++)
        cin>>a[i];
    ll ans=0,ws=0;
    for(i=0;i<n;i++)
    {
        if(a[i]<=b)
        {
            ws+=a[i];
        }
        if(ws>d)
        {
            ws=0;
            ans++;
        }
    }
    cout<<ans<<"\n";

}