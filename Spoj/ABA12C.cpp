#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[110],items[110];
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k,i,j;
        cin>>n>>k;
        ll p[k+1];
        for(i=0;i<=109;i++)
        {
            dp[i]=INT_MAX;
            items[i]=0;
        }
        for(i=1;i<=k;i++)
            cin>>p[i];
        dp[0]=0;
        items[0]=0;
        for(i=1;i<=k;i++)
        {
            ll mn=INT_MAX,ind=0;
            for(j=1;j<=i;j++)
            {
                if(p[j]!=-1)
                {
                    if(p[j]+dp[i-j]<mn&&items[i-j]<n)
                    {
                        mn=dp[i-j]+p[j];
                        ind = j;
                    }
                }
            }
            if(ind!=0)
            {
                dp[i]=mn;
                items[i]=items[i-ind]+1;
            }
        }
     //   for(i=0;i<=k;i++)
       //     cout<<items[i]<<" ";
        if(dp[k]==INT_MAX||(items[k]>n))
        {
            cout<<"-1\n";
        }
        else
            cout<<dp[k]<<"\n";
    }
    return 0;
}
