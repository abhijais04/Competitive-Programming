#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sc(x) scanf("%d",&x)
int deg[100010];
struct node
{
    int id,dis;
    node(int _id, int _dis)
    {
        id = _id;
        dis = _dis;
    }
    bool operator<(node n1)const
    {
        return this->dis < n1.dis;
    }
};
struct edge
{
    int to,from;
};
vector<edge> ans;
int main()
{

    int n,k;
    sc(n); sc(k);
    vector<node> v;
    queue<node> cur,next;
    for(int i=1;i<=n;i++)
    {
        int tmp;
        cin>>tmp;
        if(tmp == 0)
            cur.push(node(i,0));
        else
            v.pb(node(i,tmp));
    }
    sort(v.begin(),v.end());
    if(cur.size()!=1)
    {
        cout<<"-1\n";
        return 0;
    }
    int cdis = 0;
    int f=1;
    for(int i=0;i<v.size();i++)
    {
        if(v[i].dis==0) continue;
        if(cdis+2 == v[i].dis)
        {
            cur = next;
            cdis++;
            while(next.size())
                next.pop();
        }
        else if(cdis+2 < v[i].dis)
        {
            f=0;
            break;
        }
        if(v[i].dis==cdis+1)
        {
            int x = cur.front().id;
            while(cur.size()&&deg[x]>=k)
            {
                cur.pop();
                x = cur.front().id;
            }
            if(cur.empty())
            {
                f = 0;
                break;
            }
            if(deg[x] < k)
            {
                ans.pb({x,v[i].id});
                deg[x]++;
                deg[v[i].id]++;
                if(deg[x]==k)
                    cur.pop();
                if(deg[v[i].id] < k)
                next.push({v[i].id,cdis+1});
            }
        }

    }
    if(f==0)
    {
        cout<<"-1\n";
    }
    else
    {
        cout<<ans.size()<<"\n";
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i].to<<" "<<ans[i].from<<"\n";
        }
    }
    return 0;
}