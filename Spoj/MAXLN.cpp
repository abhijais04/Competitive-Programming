#include <bits/stdc++.h>
using namespace std;
int main() {

	int t;
	scanf("%d",&t);
	int i;
	for(i=1;i<=t;i++)
	{
		long long r;
		scanf("%lld",&r);
		r=r*r;
		r=4*r;
		printf("Case %d: %lld.25\n",i,r);
	}
	return 0;
}
