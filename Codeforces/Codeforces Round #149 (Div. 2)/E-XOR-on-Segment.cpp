#include <bits/stdc++.h>
using namespace std;
#define ll int
#define sc(x) scanf("%d",&x)
ll ar[100001][21];
ll tree[21][400000];
ll lazy[21][400000];
ll pw[50];
ll n;
void build(ll i,ll tl,ll tr,ll node)
{
    if(tl>tr)
    return ;
    ll mid=(tl+tr)/2;
    if(tl==tr)
    {
        tree[i][node]=ar[tl][i];
        return ;
    }
    build(i,tl,mid,2*node);
    build(i,mid+1,tr,1+(2*node));
    tree[i][node]=(tree[i][2*node]+tree[i][(2*node)+1]);
    return ;
}
ll query(ll i,ll tl,ll tr,ll l,ll r,ll node)
{
    lazy[i][node]%=2;
    if(lazy[i][node]!=0)
    {
        tree[i][node]=(tr-tl+1)-tree[i][node];
        if(tl!=tr)
        {
            lazy[i][2*node]+=lazy[i][node];
            lazy[i][1+(2*node)]+=lazy[i][node];
        }
        lazy[i][node]=0;
    }
    if(tl>r||tr<l||tl>tr)
        return 0;
    if(tl>=l&&tr<=r)
        return tree[i][node];
    ll mid=(tl+tr)/2;
    return (query(i,tl,mid,l,r,2*node)+query(i,mid+1,tr,l,r,(2*node)+1));

}
void update(ll i,ll tl,ll tr,ll l,ll r,ll node)
{
    lazy[i][node]%=2;
    if(lazy[i][node]!=0)
    {
        tree[i][node]=(tr-tl+1)-tree[i][node];
        if(tl!=tr)
        {
            lazy[i][2*node]+=lazy[i][node];
            lazy[i][1+(2*node)]+=lazy[i][node];
        }
        lazy[i][node]=0;
    }
    if(tl>r||tr<l||tl>tr)
        return ;
    if(tl>=l&&tr<=r)
    {
        tree[i][node]=(tr-tl+1)-tree[i][node];  //update
        if(tl!=tr)
        {
            lazy[i][node*2]++;
            lazy[i][1+(node*2)]++;
        }
        return ;
    }
    ll mid=(tl+tr)/2;
    update(i,tl,mid,l,r,2*node);
    update(i,mid+1,tr,l,r,(2*node)+1);
    tree[i][node]=tree[i][2*node]+tree[i][1+(2*node)]; //merge
    return ;
}
int main()
{
    sc(n);
    pw[0]=1;
    for(int i=1;i<=20;i++)
        pw[i] = pw[i-1]*2LL;
    for(int i=1;i<=n;i++)
    {
        ll tmp;
        sc(tmp);
        for(int j=0;j<=20;j++)
        {
            if(tmp&(1<<j))
            ar[i][j] = 1;
            else
                ar[i][j]=0;
        }
    }
    for(int i=0;i<=20;i++)
    build(i,1,n,1);
    ll q;
    cin>>q;
    ll flag=0;
    while(q--)
    {
        ll tt;
        cin>> tt;
        if(tt==1)
        {
            ll a,b;
            sc(a); sc(b);
            long long ans = 0;
            for(int i=0;i<=20;i++)
                ans+=(long long)pw[i]*(long long)query(i,1,n,a,b,1);
            printf("%lld\n",ans);
        }
        else
        {
            ll a,b,x;
            sc(a); sc(b); sc(x);
            //cin>>a>>b>>x;
            for(int i=0;i<=20;i++)
                if(x&(1<<i))
                    update(i,1,n,a,b,1);
        }
    }
    return 0;
}