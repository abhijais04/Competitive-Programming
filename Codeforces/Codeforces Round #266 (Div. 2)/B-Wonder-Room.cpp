#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sc(x) scanf("%lld",&x)
int main()
{
    ll n,a,b;
    sc(n); sc(a); sc(b);

    n*=6LL;
    int f=0;
    if(a*b>=n)
    {
        cout<<a*b<<"\n";
        cout<<a<<" "<<b<<"\n";
        return 0;
    }
    ll a1=0,b1=0;
    ll diff = INT_MAX;
    for(ll i=1;i*i<=n;i++)
    {
        ll j = n/i;
        if(i*j==n)
        {
            if(i>=a&&j>=b)
            {
                a1=i;
                b1=j;
                break;
            }
            if(i>=b&&j>=a)
            {
                a1=j;
                b1=i;
                break;
            }
        }
        ll aa = max(a,i+1);
        ll bb = max(b,j);
        ll td = aa*bb - n;
        if(td<diff)
        {
            a1 = aa;
            b1 = bb;
            diff = td;
        }
        aa = max(a,j);
        bb = max(b,i+1);
        td = aa*bb - n;

        if(td<diff)
        {
            a1 = aa;
            b1 = bb;
            diff = td;
        }

        aa = max(a,i);
        bb = max(b,j+1);
        td = aa*bb - n;

         if(td<diff)
        {
            a1 = aa;
            b1 = bb;
            diff = td;
        }

        aa = max(a,j+1);
        bb = max(b,i);

        td = aa*bb - n;
        if(td<diff)
        {
            a1 = aa;
            b1 = bb;
            diff = td;
        }
    }
    cout<<a1*b1<<"\n";
    cout<<a1<<" "<<b1<<"\n";

}