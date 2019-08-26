#include <bits/stdc++.h>
using namespace std;
int mod=1000007;
int main() {
	int t;
	scanf("%d",&t);
	while(t--)
	{
	   long long n,ans;
	   scanf("%lld",&n);
	   ans=n*(n-1);
	   ans=ans*3;
	   ans=ans/2;
	   //ans=((n%mod)*((n-1)%mod))%mod;
	   ans=ans%mod;
	   n=(2*(n%mod))%mod;
	   ans=(((ans)%mod)+(n%mod))%mod;
	    printf("%lld\n",ans);
	}
	return 0;
}
