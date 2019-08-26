#include <bits/stdc++.h>
using namespace std;
#define ll long long
inline int read()
{
  int ret = 0;
   int c = getchar_unlocked();

  while(c<'0' || c>'9')
    c = getchar_unlocked();
  while(c>='0' && c<='9')
  {
    ret = (ret<<3) + (ret<<1) + c - '0';
    c = getchar_unlocked();
  }
        return ret;
}
ll dp[1000004];
int main()
{
    int t,e,l,i,j;
    t=read();
   // cin>>t;
    while(t--)
    {
        //int e,l,i;
        e=read();
        l=read();
        int tme[l+1];
        int en[l+1];
        tme[0]=0;
        en[0]=0;
        for(i=1;i<=l;i++)
          en[i]=read();
        for(i=1;i<=l;i++)
            tme[i]=read();
        for(i=0;i<=e;i++)
            dp[i]=0;
        for(i=1;i<=e;i++)
        {
            for(j=1;j<=l;j++)
            {
                if(en[j]<=i)
                {
                    ll x = dp[i-en[j]] + tme[j];
                    dp[i]=max(dp[i],x);
                }
            }
        }
       printf("%lld\n",dp[e]);
    }
    return 0;
}