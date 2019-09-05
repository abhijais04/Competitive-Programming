#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int cnt=0,mx=0,id=0;
vector<int> v[200100];
bool visited[200010];
vector<int> ans[200010];
void dfs(int x)
{
	if(cnt==mx) {cnt=0;id++;}
	ans[id].pb(x);
	cnt++;
	visited[x]=1;
	for(int y:v[x])
	{
		if(visited[y]) continue;
		dfs(y);
		if(cnt==mx) {cnt=0;id++;}
		ans[id].pb(x);
		cnt++;
	}
}
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        if(a==b) continue;
        else {
        	v[a].pb(b);
        	v[b].pb(a);
        }
    }
    mx = 2*n;
    mx/=k;
    if((2*n)%k!=0)
    mx++;
    dfs(1);
    
    for(int i=0;i<k;i++)
    {
    	if(ans[i].size())
    	{
    		cout<<ans[i].size()<<" ";
    		for(int j : ans[i]) cout<<j<<" ";
    		cout<<"\n";
    	}
    	else
    	cout<<"1 1\n";
    }
}