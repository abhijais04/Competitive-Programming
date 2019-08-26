#include <bits/stdc++.h>
using namespace std;
bool isvalid(char a,char b)
{
	int ans = 0;
	ans = (a - '0')*10 + (b-'0');
	return ans <= 26 && ans > 9;
}
long long solve(string &s)
{
	int n = s.length();
	vector<long long> dp(n,0);
	dp[0]=1;
	if(n==1)
		return 1;
	for(int i=1;i<n;i++)
	{
		if(s[i]-'0')
			dp[i] = dp[i-1];
		if(isvalid(s[i-1],s[i]))
			{
				if(i>1)
				dp[i]+=dp[i-2];
				else
				dp[i]+=1;
			}
		if(s[i] == '0' && s[i-1]=='0')
			return 0;
	}
	return dp[n-1];
}
int main() {
	// your code goes here
	while(1)
	{
		string s;
		cin>>s;
		long long ans;
		if(s[0]=='0')
			break;
		else
			ans = solve(s);
		cout<<ans<<"\n";
	}
	return 0;
}