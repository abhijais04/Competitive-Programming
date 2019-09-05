#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,m;
	cin>>n>>m;
	int a[m];
	for(int i=0;i<m;i++)
	cin>>a[i];
	sort(a,a+m);
	int mn=1e9;
	for(int i=0;i<m-n+1;i++)
	{
	    mn=min(mn,a[i+n-1]-a[i]);
	}
	cout<<mn<<"\n";
	return 0;
}