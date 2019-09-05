#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
ll dp[101][101];
int main()
{
    ll n,m,k,x,y;
    cin>>n>>m>>k>>x>>y;
    if(n>1)
    {
    ll nt=k/m;
    ll nr=k%m;
    ll ntt=max((ll)0,(nt-n))/(n-1);
    //int r[n+1];
    if(k>=m*n)
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        dp[i][j]=1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(i==1)
                dp[i][j]+=(ntt+1)/2;
            if(i==n)
                dp[i][j]+=(ntt/2);
            if(i!=n&&i!=1)
            dp[i][j]+=(ntt);
        }
    }
  /*)  for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    */
    ll rem_tr = (max((ll)0,nt-n)%(n-1));
    if(k<m*n)
        rem_tr=k/m;
    ll beg=-1;
    ll c=-1;
    if(k<m*n)
    {
        beg=1;
        c=1;
    }
    else if(ntt%2==1)
        {
            beg=2;
            c=1;
        }
    else
        beg=n-1;
    int cnt=0;
    ll rw=beg;
    for(ll i=beg;cnt<rem_tr;cnt++)
    {

        for(ll j=1;j<=m;j++)
        {
            dp[i][j]++;
        }
        i+=c;
        if(i==0)
        {
            i=2;
            c=1;
        }
        else if(i==n+1)
        {
            i=n-1;
            c=-1;
        }
        rw=i;
    }
    for(ll j=1;j<=nr;j++)
    {
        dp[rw][j]++;
    }
    ll mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
           // cout<<dp[i][j]<<" ";
            mn=min(dp[i][j],mn);
            mx=max(dp[i][j],mx);
        }
        cout<<"\n";
    }
    /*for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }*/
    cout<<mx<<" "<<mn<<" "<<dp[x][y]<<"\n";
    }
    else
    {
        ll nt=k/m;
        for(ll i=1;i<=n;i++)
        {
            for(ll j=1;j<=m;j++)
                dp[i][j]+=nt;
        }
        ll ntt=k%m;
        for(int i=1;i<=ntt;i++)
            dp[1][i]++;
        ll mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                mn=min(dp[i][j],mn);
                mx=max(dp[i][j],mx);
            }
        }
        /*for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<"\n";
        }*/
        cout<<mx<<" "<<mn<<" "<<dp[x][y]<<"\n";
    }
    return 0;
}