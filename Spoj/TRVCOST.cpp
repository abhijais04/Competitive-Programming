#include <bits/stdc++.h>
using namespace std;
long long d[1001];
list <pair<long long,long long> > graph[1001];
void sp(long long root)
{
    d[root]=0;
    set <pair<long long,long long> >s;
    s.insert({0,root});
    set <pair<long long,long long> >::iterator sit;
    list <pair<long long,long long> >::iterator git;
    while(!s.empty())
    {
        sit=s.begin();
     //sit;
     long long e=sit->second;
     long long wt=sit->first;
     s.erase(sit);
     for(git=graph[e].begin();git!=graph[e].end();git++)
     {
         long long v=git->first;
         long long w=git->second;
         if(d[v]>wt+w)
         {
             if(d[v]!=1e18)
             {
                 s.erase(s.find({d[v],v}));
             }
             d[v]=wt+w;
             s.insert({wt+w,v});
         }
     }

    }
}
int main()
{

//    while(t--)
    {
        long long e,i;
        scanf("%lld",&e);
        for(i=0;i<=1000;i++)
        {
            graph[i].clear();
            d[i]=1e18;
        }
        for(i=0;i<e;i++)
        {
            long long a,b,c;
            scanf("%lld%lld%lld",&a,&b,&c);
            graph[a].push_front({b,c});
            graph[b].push_front({a,c});
        }
        long long a,b;
        scanf("%lld%lld",&a,&b);
        sp(a);
        while(b--)
        {
            int q;
            scanf("%d",&q);
            if(d[q]!=1e18)
            printf("%lld\n",d[q]);
            else
            printf("NO PATH\n");
        }

    }
    return 0;
}
