#include <bits/stdc++.h>
using namespace std;
#define ll int
#define sc(x) scanf("%d",&x)
//set<ll> s;

inline int scan(){
    char c = getchar();
    int x = 0;
    while(c<'0'||c>'9'){
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<1)+(x<<3)+c-'0';
        c=getchar();
    }
    return x;
}
int nxt[200010];
ll cp[200010];
ll a[200010];
ll n;
int par(int x)
{
    if(nxt[x]==x)
        return x;
    return nxt[x] = par(nxt[x]);
}
void process(ll p, ll x)
{
    if(p>n||x<0)
        return ;
    if(a[p] < cp[p])
    {
        ll tmp = a[p];
        a[p] = min(cp[p],a[p]+x);
        x -= (a[p]-tmp);
        if(a[p]==cp[p])
        {
            nxt[p]=par(nxt[p+1]);
        }
        if(x>0)
            process(par(nxt[p+1]),x);
    }
    else
        process(par(nxt[p+1]),x);
}
int main()
{
    n = scan();
    for(int i=1;i<=n;i++)
    {
        nxt[i]=i;
        sc(cp[i]);
    }
    nxt[n+1] = n+1;
    ll m;
    m = scan();

    while(m--)
    {
        ll t;
        //sc(t);
        t = scan();
        if(t==1)
        {
            ll p,x;
            p  = scan();
            x = scan();
            process(p,x);
        }
        else
        {
            ll x; //sc(x);
            x = scan();
            printf("%d\n",a[x]);
        }
    }
    return 0;

}