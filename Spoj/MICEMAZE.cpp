#include <bits/stdc++.h>
using namespace std;
priority_queue <pair<int,int> >pq;
int main()
{
	//int t;
//	scanf("%d",&t);
//	while(t--)
	{
	int n,m,i,s,t;
	scanf("%d%d%d",&n,&s,&t);
	scanf("%d",&m);
	int dist[n+1];
	for(i=1;i<=n;i++)
	dist[i]=1e9;
	vector <pair <int,int> >v[n+1];
	for(i=0;i<m;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		v[b].push_back({a,c});
	}
	dist[s]=0;
	pq.push({-0,s});
	while(!pq.empty())
	{
		int tc=-pq.top().first;
		int tv=pq.top().second;
		pq.pop();
		vector <pair<int,int> >::iterator it;
		for(it=v[tv].begin();it!=v[tv].end();it++)
		{
			int tn=it->first;
			int t=it->second;
			if(dist[tn]>dist[tv]+t)
			{
				dist[tn]=dist[tv]+t;
				pq.push({-dist[tn],tn});
				
			}
		}
	}
	int c=0;
	for(i=1;i<=n;i++)
	{
	   if(dist[i]<=t)
	    c++;
	 // cout<<dist[i]<<" ";
	}
	printf("%d\n",c);
	}
return 0;
}