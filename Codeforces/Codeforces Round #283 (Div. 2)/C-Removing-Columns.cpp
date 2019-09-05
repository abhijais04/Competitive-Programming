#include<bits/stdc++.h>
using namespace std;
int cnt[111];
int safe[110];
int main()
{
	int n,m;
	cin>>n>>m;
	string s[n];
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
	}
	//int ans=0;
	for(int i=0;i<n-1;i++)
	{
		if(s[i][0] > s[i+1][0])
		{
			cnt[0]=1;
			safe[i]=-1;
		}
		else if(s[i][0] < s[i+1][0])
		{
			safe[i]=0;
		}
		else
		{
			safe[i]=-1;
		}
	}
	for(int i=1;i<m;i++)
	{
		
		for(int j=0;j<n-1;j++)
		{
			if(safe[j]>=0)
			{
				if(cnt[safe[j]]==0)
				{
					continue;
				}
				else
				{
					safe[j]=-1;
				}
			}
			
			if(s[j][i] > s[j+1][i])
			{
				if(safe[j]<0)
				{
					cnt[i]=1;
				}
			}
			else if(s[j][i] < s[j+1][i])
			{
				if(safe[j]<0)
				{
					safe[j]=i;
				}
			}
			
		}
	}
	int ans=0;
	for(int i=0;i<m;i++)
	ans+=cnt[i];
	cout<<ans<<endl;
	return 0;
}