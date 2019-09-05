#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ll n;
    cin>>n;
    ll a[n];
    ll ans=0,i;
    for(i=0;i<n;i++)
        cin>>a[i];
    //int ans=0;
    sort(a,a+n);
    ll curmax = 1;
    for(i=0;i<n;i++)
    {
        if(a[i]>=curmax)
        {
            a[i]=curmax;
            curmax++;
        }
    }
    cout<<curmax<<"\n";
}