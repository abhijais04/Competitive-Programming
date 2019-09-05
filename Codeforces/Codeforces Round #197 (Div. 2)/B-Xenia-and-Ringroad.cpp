#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int main()
{
    ll n,m;
    cin>>n>>m;
    ll pre=1;
    ll ans=0;
    while(m--)
    {
        ll tmp;
        cin>>tmp;
        if(tmp>=pre)
            ans+=(tmp-pre);
        else
            ans+=(n-(pre-tmp));
        pre=tmp;
    }
    cout<<ans<<"\n";
    return 0;
}