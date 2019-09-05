#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
int dp[100010],rdp[100100];
int main()
{
    //while(1)
    {
    int n;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++)
        cin>>a[i];
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(a[i]>a[i-1])
            dp[i]=dp[i-1]+1;
        else
            dp[i]=1;
    }
    rdp[n]=1;

    for(int i=n-1;i>=1;i--)
    {
        if(a[i]<a[i+1])
            rdp[i]=rdp[i+1]+1;
        else
            rdp[i]=1;
    }
  /*  for(int i=1;i<=n;i++)
        cout<<dp[i]<<" ";
    cout<<"\n";
    for(int i=1;i<=n;i++)
        cout<<rdp[i]<<" ";
    cout<<"\n";
   */ int ans=1;
    for(int i=2;i<=n;i++)
    {
        if(dp[i]==1)
        {
            if(i<n)
            {
                if(a[i+1]-a[i-1]>=2)
                    ans=max(ans,dp[i-1]+rdp[i+1]+1);
                else
                    ans=max(ans,dp[i-1]+1);
            }
            else
            {
                ans=max(ans,dp[i-1]+1);
            }
        }
        else
        {
            ans=max(ans,dp[i]);
        }
       // if(ans==4)
         //   cout<<i<<"\n";
    }
    for(int i=n-1;i>=1;i--)
    {
        if(rdp[i]==1)
        {
            if(i>1)
            {
                if(a[i+1]-a[i-1]>=2)
                    ans=max(ans,rdp[i+1]+dp[i-1]+1);
                else
                    ans=max(ans,rdp[i+1]+1);
            }
            else
            {
                ans=max(ans,rdp[i+1]+1);
            }
        }
        else
            ans=max(ans,rdp[i]);
        //if(ans==4)
         //   cout<<i<<" rdp \n";
    }
    ans=min(ans,n);
    cout<<ans<<"\n";
    }
    return 0;

}