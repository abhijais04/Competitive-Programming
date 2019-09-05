#include <bits/stdc++.h>
using namespace std;
#define pb push_back
struct node
{
    char ch;
    int cnt;
    node() {}
    
    node(char _ch,int _cnt)
    {
        ch = _ch;
        cnt = _cnt;
    }
};
int main() {
	string str;
	cin>>str;
	int l = str.length();
	vector<node> v;
	v.pb(node(str[0],1));
	for(int i=1;i<l;i++)
	{
	    int p = v.size()-1;
	    if(str[i]==str[i-1])
	    v[p].cnt++;
	    else
	    v.pb(node(str[i],1));
	}
	int n=v.size();
	for(int i=0;i<n;i++)
	{
	    if(v[i].cnt>=3)
	    v[i].cnt=2;
	    if(i>0)
	    {
	        //if()
	        if(v[i].cnt>=2&&v[i-1].cnt>=2)
	        {
	            v[i-1].cnt=2;
	            v[i].cnt=1;
	        }
	    }
	}
	for(int i=0;i<n;i++)
	{
	    for(int j=0;j<v[i].cnt;j++)
	        putchar(v[i].ch);
	}
	//cout<<"\n";
	return 0;
}