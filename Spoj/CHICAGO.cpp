#include<bits/stdc++.h>
using namespace std;
double cost[110][110];
int main()
{
while(1)
    {
    	int n,m;
		cin>>n;//>>m;
if(n==0)
    break;
cin>>m;
	int i,j,k;
	for(i=1;i<=n;i++)
	{
	    for(j=1;j<=n;j++)
		cost[i][j]=-100;
	}
	for(i=1;i<=n;i++)
		cost[i][i]=0;
	for(i=0;i<m;i++)
	{
		int a,b;
		double c;
		cin>>a>>b;
		cin>>c;
		cost[a][b]=c/100.0;
		cost[b][a]=c/100.0;
	}
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			cost[i][j]=max(cost[i][j],cost[i][k]*cost[k][j]);
		}
	}
    printf("%.6lf percent\n",cost[1][n]*100.0 +  1e-10);
}
return 0;
}
