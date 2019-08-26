#include <bits/stdc++.h>
using namespace std;
#define ll long long
inline int read()
{
  ll ret = 0;
   ll c = getchar_unlocked();

  while(c<'0' || c>'9')
    c = getchar_unlocked();
  while(c>='0' && c<='9')
  {
    ret = (ret<<3) + (ret<<1) + c - '0';
    c = getchar_unlocked();
  }
        return ret;
}
ll dp[210][210][210];
ll n,a[500];
ll fn(ll i,ll p_i,ll p_d)
{
    if(i==n+1)
    {
        if(a[i]>a[p_i])
            return 1;
        if(a[i]<a[p_d])
            return 1;
        return 0;
    }
    if(dp[i][p_i][p_d]>=0)
    {
        return dp[i][p_i][p_d];
    }
    ll t1=fn(i+1,p_i,p_d);
    ll t2=-1000,t3=-1000;
    if(a[i]>a[p_i])
    {
        t2=1+fn(i+1,i,p_d);
    }
    if(a[i]<a[p_d])
    {
        t3=1+fn(i+1,p_i,i);
    }
    return dp[i][p_i][p_d]=max(t1,max(t2,t3));
}
int main()
{
    //int t;
    //cin>>t;
    while(1)
    {
        cin>>n;
        if(n==-1)
            break;
        ll i;
        for(i=0;i<=n+2;i++)
        {
            for(int j=0;j<=n+2;j++)
            {
                for(int k=0;k<=n+2;k++)
                    dp[i][j][k]=-10000;
            }
        }
        a[0]=-10000;
        a[1]=INT_MAX;
        for(i=2;i<=n+1;i++)
            a[i]=read();
        cout<<n-fn(2,0,1)<<"\n";
    }
    return 0;
}
