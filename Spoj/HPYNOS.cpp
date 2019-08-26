#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	scanf("%d",&n);
	int arr[1000];
	int sz=0,flag=0,c=0;
	int tmp=n;
	while(1)
	{
		if(tmp==1||flag==1)
		break;
		arr[sz++]=tmp;
		int sum=0;
		while(tmp)
		{
			sum=sum+((tmp%10)*(tmp%10));
			tmp=tmp/10;
		}
		tmp=sum;
		for(int i=0;i<sz;i++)
		{
			if(arr[i]==tmp)
			{flag=1;break;}
		}
		c++;
	}
	if(flag==1)
	printf("-1\n");
	else if(tmp==1)
	printf("%d\n",c);
	return 0;
}
