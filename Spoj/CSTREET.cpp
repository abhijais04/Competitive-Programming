#include <iostream>
#include <cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int par[10001];
int rnk[10001];
struct edge
{
    int cost,start,last;
    edge(int a,int b,int c)
    {
        this->start=a;
        this->last=b;
        this->cost=c;
    }

};
bool cmp(const edge& e1,const edge& e2)
{
    return (e1.cost<e2.cost);
}
int fnd(int x)
    {
        if(x==par[x])
            return x;
        else
        return fnd(par[x]);
    }
    void join(int a,int b)
    {
        if(rnk[a]>rnk[b])
        {
          par[b]=a;
        }
        else if(rnk[b]>rnk[a])
        {
            par[a]=b;
        }
        else
        {
            par[b]=a;
            rnk[a]++;
        }
    }
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int price;
        scanf("%d",&price);
        int ans=0;
        int n,m,i;
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
        {
            par[i]=i;
            rnk[i]=0;
        }
    vector <edge>v;
    for(i=0;i<m;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        v.push_back(edge(a,b,c));
    }

    sort(v.begin(),v.end(),cmp);
    //cout<<"asdaf\n";
    for(i=0;i<v.size();i++)
    {
     //   cout<<"i : "<<i<<"\n";
      //  cout<<v[i].start<<" "<<v[i].last<<"\n";
        int root1=fnd(v[i].start);
        int root2=fnd(v[i].last);
      //  cout<<root1<<" "<<root2<<"\n";
        if(root1!=root2)
        {
            join(root1,root2);
            ans+=v[i].cost;
        }
    }
    //cout<<"asdaf\n";
    printf("%d\n",ans*price);
    }
    return 0;
}
