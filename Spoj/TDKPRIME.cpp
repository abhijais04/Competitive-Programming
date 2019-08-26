#include <bits/stdc++.h>
using namespace std;
bool a[86028122]={false};
int p[86028122];
int n=86028122;
void seive()
{
	for(int i=3;i*i<=n;i=i+2)
	{
		if(a[i]==false)
		{
         for(int j=3;j*i<=n;j=j+2)
			{
				a[j*i]=true;
			}
		}
	}
}
int main() {


	long long t,i;
	int q;
scanf("%lld",&t);
	p[0]=2;
int z=1;
	seive();
	for(i=3;i<=n;i+=2)
	{
		if(a[i]==false)
		{
			p[z++]=i;
        }
	}
	while(t--)
	{
		scanf("%d",&q);
	printf("%d\n",p[q-1]);
	}
	return 0;
}
