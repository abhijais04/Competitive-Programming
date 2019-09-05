#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sc(x) scanf("%lld",&x)
ll deg[1000010];
int edge[1000010];
int par[1000010];
int fnd(int x)
{
    if(x==par[x]) return x;
    return par[x] = fnd(par[x]);
}
int main()
{
    ll n,m;
    sc(n); sc(m);
    ll loop=0;
    ll root;
    ll mm = m;
    for(int i=1;i<=n;i++)
        par[i] = i;
    while(mm--)
    {
        ll a,b;
        sc(a); sc(b);
        edge[a] = 1; edge[b] = 1;
        root = a;
        par[fnd(a)] = fnd(b);
        if(a==b)
        {
            loop++;
            continue;
        }
        deg[a]++;
        deg[b]++;
    }
    for(int i=1;i<=n;i++)
    {
        if(edge[i]&& fnd(i)!=fnd(root))
        {
            cout<<"0\n";
            return 0;
        }
    }
    ll ans  = 0;
    for(int i=1;i<=n;i++)
    {
        ans+= ((deg[i])*(deg[i]-1))/2;
    }

    ans += loop*(m-loop);
    ans += loop*(loop-1)/2;
    cout<<ans<<"\n";
    return 0;
}