#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ans[190][190];
ll arr[4]={1,-1,0,0};
ll brr[4]={0,0,1,-1};
char s[200][200];
ll n,m;
void bfs(ll i1,ll j1)
{
    list <pair<ll,ll> >q;
    q.push_back({i1,j1});
    while(!q.empty())
    {
        ll i=q.front().first;
        ll j=q.front().second;
        q.pop_front();
        for(ll k=0;k<4;k++)
        {
            ll x=i+arr[k],y=j+brr[k];
            if(x>=0&&y>=0&&x<n&&y<m)
            {
                if(ans[x][y]>1+ans[i][j])
                {
                    q.push_back({x,y});
                    ans[x][y]=1+ans[i][j];

                }
               // visited[x][y]=1;
            }
        }
    }
    return ;
}
int main()
{
    ll t,i,j;
    cin>>t;

    while(t--)
    {
        for(i=0;i<182;i++)
        {
            for(j=0;j<182;j++)
                ans[i][j]=100000000;
        }
        cin>>n>>m;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            cin>>s[i][j];
        }
        
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(s[i][j]=='1')
                {
                    ans[i][j]=0;
                    bfs(i,j);
                }
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
                cout<<ans[i][j]<<" ";
            cout<<"\n";
        }
        cin.ignore();
    }
    return 0;
}
