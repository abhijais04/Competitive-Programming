#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sc(x) scanf("%lld",&x)
ll num[20];
ll dp[1<<18][101];
ll pw[20],fact[20];
int main()
{
	string s;
	ll m;
	cin>>s;
	sc(m);
	fact[0]=1;
	pw[0] = 1%m;
	for(int i=1;i<=19;i++)
	{
		pw[i] = pw[i-1]*10LL;
		pw[i]%=m;
		fact[i] = fact[i-1]*i;
	}
	ll l = s.length();
	for(int i=0;i<l;i++)
	{
		s[i]-='0';
		num[s[i]]++;
	}
	
	dp[0][0]=1;
	ll lim = 1<<l;
	lim--;
	
	for(int i=0;i<=lim;i++)
	{
		int ln = 0;
		for(int j=0;j<l;j++)
		{
			if(i & (1<<j) )
				ln++;
		}
		
		for(int j=0;j<l;j++)
		{
			if(i & (1<<j)) continue;
			if((ln==l-1) && !s[j]) continue;
			
			for(int k=0;k<m;k++)
			{
				int r2 = k + pw[ln]*s[j];
				r2%=m;
				dp[i|(1<<j)][r2] += dp[i][k];
			}
		}
	}
	
/*	for(int i=0;i<=lim;i++)
	{
		for(int j=0;j<m;j++)
		cout<<dp[i][j]<<" ";
		cout<<"\n";
	}
*/	ll ans = dp[lim][0];
//	cout<<ans<<"\n";
	for(int i=0;i<=9;i++)
	ans/=fact[num[i]];
	
	cout<<ans<<"\n";
	
	
}