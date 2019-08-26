#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b)
{
    while(a)
    {
        long long tmp=b%a;
        b=a;
        a=tmp;
    }
    return b;
}
long long me(long long a,long long b,long long m)
{
	long long ans=1;
	while(b>0)
	{
		if(b&1)
		{
			ans=(ans*a)%m;
		}
		a=(a*a)%m;
	}
	return ans;
}
int main() {

	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long a;
		char ch[260];
		scanf("%lld",&a);
		scanf("%s",&ch);
		if(a==0)
		printf("%s\n",ch);
		else
		{
			long long tmp=0,l=strlen(ch);
			for(int i=0;i<l;i++)
			{
				tmp=(((tmp*10)%a)+(ch[i]-'0'))%a;
			}
			printf("%lld\n",gcd(a,tmp));
		}
	}
	return 0;
}
