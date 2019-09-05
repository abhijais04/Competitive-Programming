#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
vector<int> v[201000];
int cl[200010];
int visited[201000];
//unordered_set<int> s;
void dfs(int x,int par,int cpar)
{
    set<int> tmp;
    if(par!=0)
        tmp.insert(cpar);
    int xx=1;
    tmp.insert(cl[x]);
    for(int i=0;i<v[x].size();i++)
    {
        int y = v[x][i];
        if(y!=par)
        {
            while(tmp.find(xx)!=tmp.end())
                xx++;
            cl[y] = xx;
            tmp.insert(xx);
            xx++;
            dfs(y,x,cl[x]);
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }

    int ans=INT_MIN;
    int mv=1;
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,(int)v[i].size()+1);
        if(v[mv].size()<v[i].size())
            mv=i;
    }
    printf("%d\n",ans);
    //cl[mv]=1;
    cl[1]=1;
    dfs(1,0,0);
    for(int i=1;i<=n;i++)
    printf("%d ",cl[i]);
    cout<<"\n";
    return 0;
}