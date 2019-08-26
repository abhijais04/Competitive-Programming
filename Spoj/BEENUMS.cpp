#include <bits/stdc++.h>
using namespace std;

int main() {
	while(1)
	{
	    long long n,flag=0;
	    scanf("%lld",&n);
	    if(n==-1)
	    break;
	    if((n%6)==1)
	    {
	        n=n/6;
	        n=8*n;
	        n=n+1;
	        long long x=sqrt(n);
	        if(x*x==n)
	        {
	            x++;
	            if(x%2==0)
	            flag=1;
	            else
	            flag=0;
	        }
	        else
	        flag=0;
	    }
	    else
	    flag=0;
	    if(flag==0)
	    printf("N\n");
	    else
	    printf("Y\n");
	}
	return 0;
}
