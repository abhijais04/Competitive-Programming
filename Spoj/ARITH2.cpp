#include<bits/stdc++.h>
using namespace std;
long long val(long long a,long long b,char ch)
{
	if(ch=='+')
	return (a+b);
	if(ch=='-')
	return (a-b);
	if(ch=='*')
	return (a*b);
	if(ch=='/'&&b!=0)
	return (a/b);
	else
	return a;
}
int main()
{
	long long t;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("\n");
		long long a,b,c;
		scanf("%lld",&a);
		char ch[3];
		while(1)
		{
		    scanf("%s",&ch);
		    if(ch[0]=='=')
		    break;
		    scanf("%lld",&b);
		    c=val(a,b,ch[0]);
		    a=c;
		    
		}
		
	    printf("%lld\n",a);
	}
	return 0;
}