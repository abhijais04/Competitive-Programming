#include <bits/stdc++.h>
using namespace  std;
int main()
{
	while(1)
	{
		int a,b;
		cin>>a>>b;
		if((a==-1)||(b==-1))
			break;
		else
		{
			int mi,mx;
			mi=(a>b?b:a);
			mx=(b>a?b:a);
			mi++;
			int z=mx/mi;
			if(z*mi!=mx)
			z++;
			cout<<z<<"\n";
		}
	}
	return 0;
}