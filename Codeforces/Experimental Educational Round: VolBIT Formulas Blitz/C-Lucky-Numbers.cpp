#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long

int main()
{
    ios_base::sync_with_stdio(NULL);
    ll n;
    cin>>n;
    ll ans=0;
    ll tmp=1;
    for(int i=0;i<n;i++)
    {
        tmp=tmp*(ll)2;
        ans+=tmp;
    }
    cout<<ans<<"\n";
    return 0;
}