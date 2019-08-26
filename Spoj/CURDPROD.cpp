#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	scanf("%d",&t);
	while(t--)
    {
        long long n,l,i;
        scanf("%lld%lld",&n,&l);
        long long a[n];
        for(i=0;i<n;i++)
            scanf("%lld",&a[i]);
       // sort(a,a+n);
        long long low=1,high=a[n-1]*l;
        while(low<high)
        {
            long long mid=(low+high)/2;
            long long tw=0;
            for(i=0;i<n;i++)
            {
                tw=tw+(mid/a[i]);
            }
            if(tw<l)
            {
                low=mid+1;
            }
            else
            {
                high=mid;
            }
        }
        printf("%lld\n",high);

    }
	return 0;
}
