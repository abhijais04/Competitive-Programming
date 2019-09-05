#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sc(x) scanf("%d",&x)
ll query[200010],a[200010],b[200010];
int main()
{

    int n,q;
    sc(n); sc(q);
    for(int i=0;i<n;i++) sc(a[i]);
    while(q--)
    {
        int l,r;
        sc(l); sc(r);
        l--;r--;
        query[l]++; query[r+1]--;
    }
    ll cs=0;
    for(int i=0;i<n;i++)
    {
        cs+=query[i]; b[i]=cs;
    }
    sort(b,b+n); sort(a,a+n);
    cs=0;
    for(int i=0;i<n;i++) cs+=(a[i]*b[i]);
    printf("%lld\n",cs);
    return 0;
}