#include <bits/stdc++.h>
using namespace std;
int main() {
	int c=1;
	while(1)
	{
		long long n;
		scanf("%lld",&n);
		int p = (n>1)?(n-2):1;
		if(n==0)
		break;
		else
		{
		    long long ans=1;
		    while(p--)
            {
                ans=ans*n;
            }
		    printf("Case %d, N = %lld, # of different labelings = %lld\n",c,n,ans);
		}
		c++;
	}
	return 0;
}
