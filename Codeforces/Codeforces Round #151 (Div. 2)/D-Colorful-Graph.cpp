#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
vector<int> v[100010];
map<int,vector<int> > mp;
int clr[100100];
int get(int x)
{
    int cnt=0;
    vector<int> tmp=mp[x];
    set<int> ts;
    for(int i=0;i<tmp.size();i++)
    {
        int xx=tmp[i];
        for(int j=0;j<v[xx].size();j++)
        {
            int tcl = clr[v[xx][j]];
            if(tcl!=x)
                ts.insert(tcl);
        }
    }
    return (int)ts.size();
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int c;
        cin>>c;
        clr[i]=c;
        mp[c].pb(i);
    }
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    map<int,vector<int> >::iterator it;
    int ans=0,mx=0,tans=0;
    for(it=mp.begin();it!=mp.end();it++)
    {

        int cl=it->first;
        if(it==mp.begin())
            tans=cl;
        int cn=get(cl);
        if(cn>mx)
            {
                ans=cl;
                mx=cn;
            }
    }
    if(ans)
    cout<<ans<<"\n";
    else
        cout<<tans<<"\n";

}