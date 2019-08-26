#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d",&n);
	char ch[4];
	int a=0,b=0,c=0;
	int i;
	for(i=0;i<n;i++)
	{
	    scanf("%s",&ch);
	    if(ch[0]=='1'&&ch[2]=='2')
	    a++;
	    else if(ch[0]=='1'&&ch[2]=='4')
	    b++;
	    else
	    c++;
	}
//	cout<<a<<" "<<b<<" "<<c<<"\n";
	int v1=0,v2=0;
	if(c<=b)
	{
	    v1=c+(b-c)/4;
	    b=(b-c)%4;
	    c=0;
	}
	else if(c>b)
	{
	    v1=c;
	    b=0;
	}
	c=0;
	v2=a/2;
	a=a%2;
	int v3=0;
	if(a==1&&b==3)
	{
	    v3=2;
	}
	else if(a>0||b>0)
	v3=1;
	else
	v3=0;
	printf("%d\n",v1+v2+v3+1);
	return 0;
}
