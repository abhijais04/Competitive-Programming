#include <iostream>
#include<cstdio>
using namespace std;
int main() {
int t;
scanf("%d",&t);
while(t--)
{
	int a,b;
	scanf("%d%d",&a,&b);
	int max1=0,max2=0;
	while(a--)
	{
		int n1;
		scanf("%d",&n1);
		if(n1>max1)
		max1=n1;
	}
	while(b--)
	{
		int n2;
		scanf("%d",&n2);
		if(n2>max2)
		max2=n2;
	}
	if((max1>max2)||(max1==max2))
	{
		printf("Godzilla\n");
	}
	else if(max2>max1)
	{
		printf("MechaGodzilla\n");
	}
}
	return 0;
}