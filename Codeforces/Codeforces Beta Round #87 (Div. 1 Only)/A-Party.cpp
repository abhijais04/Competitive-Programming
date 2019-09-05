#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
vector<int> v[100010];
bool visited[100010];
int dp[100010];
int dfs(int x)
{
    if(visited[x])
        return dp[x];
    int ans=0;
    for(int i=0;i<v[x].size();i++)
    {
        ans=max(ans,dfs(v[x][i]));
    }
    dp[x]=ans+1;
    return ans+1;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int tmp;
        cin>>tmp;
        if(tmp!=-1)
            v[tmp].pb(i);
    }
    int ans=0;

    for(int i=1;i<=n;i++)
    {

        if(!visited[i])
        {
            ans=max(ans,dfs(i));
        }
        //cout<<dp[i]<<"\n";
    }
    cout<<ans<<"\n";
}