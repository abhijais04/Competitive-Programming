#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll gcd(ll a,ll b)
{
    while(b)
    {
        ll tmp=a%b;
        a=b;
        b=tmp;
    }
    return a;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll a,i;
        cin>>a;
        for(i=a/2;i>=1;i--)
            if(gcd(a,i)==1)
        {cout<<i<<"\n";break;}
    }
}
