#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
int main()
{
    string n;
    cin>>n;
    int l=n.length();
    int nn = n[l-1]-'0';
    if(l>1)
    {
        nn=nn+(n[l-2]-'0')*10;
    }
    nn%=4;
    ll ans=0;
    for(ll i=1;i<=4;i++)
    {
        ans =ans+pow(i,nn);
    }
    ans%=5;
    cout<<ans<<"\n";
}