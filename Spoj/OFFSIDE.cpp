#include <bits/stdc++.h>
using namespace std;

int main() {
	while(1)
	{
		int n1,n2,i,j;
		scanf("%d%d",&n1,&n2);
		if(n1==0&&n2==0)
		break;
		int a1[n1],a2[n2];
		for(i=0;i<n1;i++)
		scanf("%d",&a1[i]);
		for(i=0;i<n2;i++)
		scanf("%d",&a2[i]);
		sort(a1,a1+n1);
		sort(a2,a2+n2);
		if((a1[0]<a2[0])||a1[0]<a2[1])
		printf("Y\n");
		else
		printf("N\n");
	}
	return 0;
}
