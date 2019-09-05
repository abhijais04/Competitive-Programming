#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
ll a[100],pw[100];
ll fn(ll n)
{
    if(n<10)
        return n;
    ll tmp = n;
    int t=log10(n);
    if(n!=pw[t])
    return a[t]+(n-pw[t])*(t+1);
    else
        return a[t];

}
int main()
{
    a[1]=11;
    ll tmp=9;
    pw[0]=1;
    pw[1]=10;
    for(ll i=2;i<=12;i++)
    {
        tmp*=10;
        a[i]=a[i-1]+((tmp-1)*i)+(1+i);
       // cout<<a[i]<<" ";
        pw[i]=pw[i-1]*10;
    }
    //while(1)
    {
        ll n;
    cin>>n;
    cout<<fn(n)<<"\n";
    }

}