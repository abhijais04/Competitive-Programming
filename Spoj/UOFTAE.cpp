#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define gc getchar
//_unlocked
int read() {
  char c = gc();
  while(c<'0' || c>'9') c = gc();
  int ret = 0;
  while(c>='0' && c<='9') {
    ret = 10 * ret + c - 48;
    c = gc();
  }
  return ret;
}
ll dp[210][210],n,m,a[210],b[210];
ll fn(ll i,ll lft)
{
    if(lft<0)
        return 0 ;
    if(i>m||i<0)
        return 0;
    if(i==m)
    {
        if(lft==0)
            return 1;
        else
            return 0;
    }
    if(dp[i][lft]!=0)
        return dp[i][lft];
    for(ll j=a[i];j<=b[i];j++)
    {
        dp[i][lft]+=fn(i+1,lft-j);
    }
    return dp[i][lft];
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>m>>n;
       // if(m==0&&n==0)
        //    break;
        for(ll i=0;i<=m;i++)
        {

            for(ll j=0;j<=n;j++)
            {
                dp[i][j]=0;
            }
        }
        for(ll i=0;i<m;i++)
        {
            cin>>a[i];
            cin>>b[i];
        }
        cout<<fn(0,n)<<"\n";
    }
    return 0;
}
