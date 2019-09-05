#include<bits/stdc++.h>
using namespace std;
#define ll long long int
struct node{
	float dis;
	ll x;ll y;
};
bool cmp(node a,node b)
{
	if(a.dis<=b.dis)
	return true;
	else
	return false;
}
int main()
{
    ios::sync_with_stdio(false);
	ll n;
	cin>>n;
	node a[n];
	ll i,f=0;
	for(i=0;i<n;i++)
	{
		cin>>a[i].x>>a[i].y;
		if(a[i].x!=0)f+=2;
		if(a[i].y!=0)f+=2;
		float z=a[i].x*a[i].x;float m=a[i].y*a[i].y;
		float d=sqrt(z+m);
		a[i].dis=d;
	}
	sort(a,a+n,cmp);
	f+=n*2;
	cout<<f<<endl;
	for(i=0;i<n;i++)
	{
		if(a[i].x!=0)
		{
			if(a[i].x<0)
			cout<<"1 "<<abs(a[i].x)<<" L"<<endl;
			if(a[i].x>0)
			cout<<"1 "<<abs(a[i].x)<<" R"<<endl;
			
		}
		if(a[i].y!=0)
		{
			if(a[i].y<0)
			cout<<"1 "<<abs(a[i].y)<<" D"<<endl;
			if(a[i].y>0)
			cout<<"1 "<<abs(a[i].y)<<" U"<<endl;
		}
		cout<<"2\n";
		a[i].x*=-1;a[i].y*=-1;
		if(a[i].x!=0)
		{
			if(a[i].x<0)
			cout<<"1 "<<abs(a[i].x)<<" L"<<endl;
			if(a[i].x>0)
			cout<<"1 "<<abs(a[i].x)<<" R"<<endl;
			
		}
		if(a[i].y!=0)
		{
			if(a[i].y<0)
			cout<<"1 "<<abs(a[i].y)<<" D"<<endl;
			if(a[i].y>0)
			cout<<"1 "<<abs(a[i].y)<<" U"<<endl;
		}
		cout<<"3\n";
	}
}