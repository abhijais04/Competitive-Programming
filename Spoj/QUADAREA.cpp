#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    double a[4],sum=0;
	    for(int i=0;i<4;i++)
	    {
	        scanf("%lf",&a[i]);
	        sum=sum+a[i];
	    }
	    sum=sum/2.0;
	    sum=sqrt((sum-a[0])*(sum-a[1])*(sum-a[2])*(sum-a[3]));
	    printf("%.2lf\n",sum);
	}
	return 0;
}
