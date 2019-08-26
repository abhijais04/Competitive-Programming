#include<bits/stdc++.h>
using namespace std;
int phi[1010000];
int n=1000001;
void phif()
{
	
	for(int i=1;i<=n;i++)
	{
		phi[i]=i;
	}
	for(int i=2;i<=n;i++)
	{
		if(phi[i]==i)
		for(int j=i;j<=n;j+=i)
		{
			phi[j]-=(phi[j]/i);
		}
	}
}
int main()
{
	phif();
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a;
		scanf("%d",&a);
		printf("%d\n",phi[a]);
	}
	return 0;
}