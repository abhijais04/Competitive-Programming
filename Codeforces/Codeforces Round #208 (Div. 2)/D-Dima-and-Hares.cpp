#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int a[3010],b[3010],c[3010];
int dp[3010][2];
int n;
int fn(int pos,int pre)
{
    if(pos==n-1)
    {
        if(pre) return b[pos];
        return a[pos];
    }
    if(dp[pos][pre]!=-1)
        return dp[pos][pre];
    int r1,r2;
    if(pre==0)
    {
        r1 = a[pos]+fn(pos+1,1);
        r2 = b[pos]+fn(pos+1,0);
    }
    else
    {
        r1 = b[pos]+fn(pos+1,1);
        r2 = c[pos]+fn(pos+1,0);
    }

    return dp[pos][pre] = max(r1,r2);
}
int main()
{
    memset(dp,-1,sizeof(dp));
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>b[i];
    for(int i=0;i<n;i++)
        cin>>c[i];
    cout<<fn(0,0)<<"\n";
    return 0;
}