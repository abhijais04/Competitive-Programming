#include <bits/stdc++.h>
using namespace std;

int main() {

			int n;
			scanf("%d",&n);
			unsigned long long a,b=0;
			while(n--)
			{
				scanf("%llu",&a);
				b=b^a;
			}
			printf("%llu\n",b);

	return 0;
}
