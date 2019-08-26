#include <bits/stdc++.h>
using namespace std;
int dp[2002][2002];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int ans=0,i,j;
        vector <int>a,b;
        a.push_back(-9);
        while(1)
        {
            int x;
            cin>>x;
            if(x==0)
                break;
            else
            a.push_back(x);
        }
        while(1)
        {
            b.clear();
            b.push_back(-1);
            while(1)
            {
                int x;
                cin>>x;
                if(x==0)
                    break;
                else
                b.push_back(x);
            }
            if(b.size()==1)
                break;
            for(i=0;i<=b.size();i++)
            {
                for(j=0;j<=a.size();j++)
                    dp[i][j]=0;
            }
            for(i=1;i<=b.size();i++)
            {
                for(j=1;j<a.size();j++)
                {
                    if(a[j]==b[i])
                    {
                        dp[i][j]=dp[i-1][j-1]+1;
                    }
                    else
                    {
                        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                    }
                   // cout<<dp[][j]<<" ";
                }
             //   cout<<"\n";
            }
            ans=max(ans,dp[b.size()-1][a.size()-1]);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
