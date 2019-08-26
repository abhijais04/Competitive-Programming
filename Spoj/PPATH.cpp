#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define MOD 1000000007
#define LIMIT 200000
using namespace std;
typedef long long ll; typedef long double ld; typedef unsigned long long ull;
typedef vector<int> vi; typedef pair<int, int> ii; typedef vector<pair<int, int> > vii; typedef vector< vector< pair<int, int> > > vvii;
typedef vector< vector < int > > vvi; typedef vector< bool > vb;
template <class T>
inline void ri(T &i){
	char c; for (c = getchar(); c<'0' || c>'9'; c = getchar());
	for (i = 0; c >= '0'&&c <= '9'; c = getchar())
		i = (i << 3) + (i << 1) + (c - 48);
}
vector <int>p;
bool aq[100010];
int diff(int a,int b)
{
    int cnt=0;
    int x[4],y[4];
    int i=0;
    while(a)
    {
        x[i]=a%10;
        a=a/10;
        i++;
    }
    i=0;
     while(b)
    {
        y[i]=b%10;
        b=b/10;
        i++;
    }
    for(i=0;i<4;i++)
    {
        if(x[i]!=y[i])
            cnt++;
    }
    return cnt;

}
void seive()
{
    int i,j;
    for(i=2;i*i<=10010;i++)
    {
        if(aq[i]==0)
        {
            for(j=2*i;j<=10000;j+=i)
                aq[j]=1;
        }
    }
    for(i=1000;i<10000;i++)
    {
        if(aq[i]==0)
            p.pb(i);
    }
}
vector <int>v[10004];
int dist[10010];
bool visited[10010];
int bfs(int a,int b)
{
    if(a==b)
        return 0;
        int i;

    for(i=1000;i<10000;i++)
    {
        dist[i]=0;
        visited[i]=0;
    }
    list <int>q;
    q.pb(a);
    visited[a]=0;
    dist[a]=0;
    int flag=0;
    while(!q.empty())
    {
        int x=q.front();
        q.pop_front();
        for(i=0;i<v[x].size();i++)
        {
            if(!visited[v[x][i]])
            {
                q.pb(v[x][i]);
                visited[v[x][i]]=1;
                dist[v[x][i]]=dist[x]+1;
                if(v[x][i]==b)
                {
                    flag=1;
                    break;
                }
            }
        }
        if(flag==1)
            break;
    }
    return dist[b];
}
int main()
{
    seive();
    int i,j,k;
  //  cout<<"dfg";
    for(i=0;i<p.size();i++)
    {
        for(j=i+1;j<p.size();j++)
        {
            if(diff(p[i],p[j])==1)
            {
                v[p[i]].pb(p[j]);
                v[p[j]].pb(p[i]);
            }
        }
    }
    int t;
    ri(t);
    while(t--)
    {
        int a,b;
        ri(a);
        ri(b);
        cout<<bfs(a,b)<<"\n";
    }
}
