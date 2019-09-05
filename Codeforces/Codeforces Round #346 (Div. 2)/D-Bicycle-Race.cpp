#include <bits/stdc++.h>
using namespace std;
int main() {
	int n,i;
	cin>>n;
	vector <pair<int,int> >v;
	for(i=0;i<=n;i++)
	{
	    int x,y;
	    cin>>x>>y;
	    v.push_back(make_pair(x,y));
	    //if(i==1)
	  //  v.push_back({x,y});
	}
	int c=0;
	for(i=1;i<n;i++)
	{
	    if(v[i].first!=v[i-1].first)
	    {
	        int diff=v[i].first-v[i-1].first;
	        if(diff>0)
	        {
	            if(v[i+1].second>v[i].second)
	            c++;
	        }
	        else if(diff<0)
	        {
	            if(v[i+1].second<v[i].second)
	            {
	                c++;
	            }
	        }
	    }
	    if(v[i].second!=v[i-1].second)
	    {
	        int diff=v[i].second-v[i-1].second;
	        if(diff>0)
	        {
	            if(v[i+1].first<v[i].first)
	            c++;
	        }
	        else if(diff<0)
	        {
	            if(v[i+1].first>v[i].first)
	            {
	                c++;
	            }
	        }
	    }
	}
	cout<<c<<"\n";
	return 0;
}