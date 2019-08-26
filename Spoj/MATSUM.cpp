#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll tree[1030][1030];
ll m[1030][1030];
ll max_x,max_y;
void update2(ll x,ll y,ll val)
{
    while(y<=max_y)
    {
        tree[x][y]+=val;
        y+=(y&-y);
    }
}
void update(ll x,ll y,ll val)
{
    while(x<=max_x)
    {
        update2(x,y,val);
        x+=(x&-x);
    }
}
ll getval(ll x,ll y)
{
    ll ans=0;
    while(x>0)
    {
        ll y1=y;
        while(y1>0)
        {
            ans+=tree[x][y1];
            y1-=(y1&-y1);
        }
        x-=(x&-x);
    }
    return ans;
}
int main()
{
    ll t,i,j;
    cin>>t;
    while(t--)
    {
        ll n;
        scanf("%lld",&n);
        for(i=0;i<=n;i++)
        {
            for(j=0;j<=n;j++)
            {
                tree[i][j]=0;
                m[i][j]=0;
            }
        }
        max_x=max_y=n;
        while(1)
        {
            char s[10];
            //cin>>s;
            scanf("%s",&s);
            if(s[1]=='E')
            {
                ll a,b,val;
                scanf("%lld%lld%lld",&a,&b,&val);
                //cin>>a>>b>>val;
               ll temp = val-m[a][b];
                m[a][b]=val;
                update(a+1,b+1,temp);
            }
            else if(s[1]=='U')
            {
                ll a,b,x,y;
                scanf("%lld%lld%lld%lld",&a,&b,&x,&y);
                //cin>>a>>b>>x>>y;
                ll ans= getval(x+1,y+1)+getval(a,b)-getval(a,y+1)-getval(x+1,b);
                printf("%lld\n",ans);
            }
            else
                break;
        }
    }
    return 0;
}
