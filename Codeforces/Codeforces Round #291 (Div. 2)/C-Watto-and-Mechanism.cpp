#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pp pair<ll,ll>
ll mo=98525375321;
map<pp,ll>mm;
int main()
{
	ios::sync_with_stdio(false);
	ll n,m;
	cin>>n>>m;
	string s[n];
	ll i,j;
	for(i=0;i<n;i++)
	cin>>s[i];
	for(i=0;i<n;i++)
	{
		string p=s[i];
		ll x=p.length();
		ll f=0;
		for(j=0;j<x;j++)
		{
			f=(f*10+s[i][j]-'a'+1)%mo;
		}
		//cout<<f<<endl;
		mm[{f,x}]++;
	}
	//string t[m];
	for(i=0;i<m;i++)
	{
		ll kk=0;
		string p;
		cin>>p;
		ll f=0,x=p.length();
		for(j=0;j<x;j++)
		{
			f=(f*10+p[j]-'a'+1)%mo;
		}
		ll g=1;
		for(j=x-1;j>=0;j--)
		{
			if(p[j]=='a')
			{
				ll fg=(f+(-g+2*g)+mo)%mo;
				ll ff=(f+(-g+3*g)+mo)%mo;
				if(mm[{ff,x}]||mm[{fg,x}])
				{
					cout<<"YES\n";
					kk=1;//return 0;
					break;
				}
			}
			else if(p[j]=='b')
			{
				ll fg=((f%mo-g%mo)%mo+mo)%mo;
				ll ff=(f+g)%mo;
				if(mm[{ff,x}]||mm[{fg,x}])
				{
					cout<<"YES\n";
					kk=1;//return 0;
					break;
				}
			}
			else
			{
				ll fg=((f%mo-2*g%mo)%mo+mo)%mo;
				
				ll ff=((f%mo-g%mo)%mo+mo)%mo;
				if(mm[{ff,x}]||mm[{fg,x}])
				{
					cout<<"YES\n";
					kk=1;//return 0;
					break;
				}
			}
			g=(g*10)%mo;
		}
		if(kk==0)
		cout<<"NO\n";
	}
}