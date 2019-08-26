#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--)
	{
	   long long n,d,m;
	    scanf("%lld%lld%lld",&n,&m,&d);
	    long long a[n],i,c=0;
	    for(i=0;i<n;i++)
	    {
	        scanf("%lld",&a[i]);
	    }
	    long long t=d*m;
	    sort(a,a+n);
	    for(i=n-1;i>=0;i--)
	    {
	        while(a[i]>d)
	        {
	            t=t-d;
	            a[i]-=d;
	        }
	    }
	    if(t>0)
	    printf("NO\n");
	    else
	    printf("YES\n");
	}
	return 0;
}
