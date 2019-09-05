#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
map<int,int> mp;
int a[100100];
int dp[4001][4001];
int cnt[4001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin>>n;
    int ans=1;
    if(n>1)
        ans=2;
    for(int i=0;i<n;i++)
        {
            cin>>a[i];
            mp[a[i]];
        }
    int ind=0;
    map<int,int>::iterator it;
    for(it=mp.begin();it!=mp.end();it++)
    {
        mp[it->first]=ind++;
    }
    int ans1=0;
    for(int i=0;i<n;i++)
        {
            a[i]=mp[a[i]];
            cnt[a[i]]++;
            ans1=max(ans1,cnt[a[i]]);
        }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            dp[i][j]=1;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
            {
                    if(a[i]!=a[j])
                dp[a[i]][a[j]]=max(dp[a[i]][a[j]],dp[a[j]][a[i]]+1);
            }
    }
//    int ans=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            ans=max(ans,dp[i][j]);
    }
    ans=max(ans,ans1);
    cout<<ans<<"\n";
}