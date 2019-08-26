#include <bits/stdc++.h>
using namespace std;
int val(int a)
{
    if(a==1)
        return 2;
    else if(a==2)
        return 1;
}
int main()
{
        int t,d=1;
        scanf("%d",&t);
        while(t--)
        {
        int n,m,flag=0;
        scanf("%d %d",&n,&m);
        list <int >l[n+1];
        int i,mark[n+1];
        bool visited[n+1];
        for(i=0;i<m;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            l[a].push_back(b);
            l[b].push_back(a);
        }
        for(i=1;i<=n;i++)
            {
                visited[i]=false;
                mark[i]=0;
            }
        visited[1]=1;
        mark[1]=1;
        list <int >q;
        int c=1;
        q.push_back(1);
        while(!q.empty())
        {
            int tmp=q.front();
           // cout<<tmp<<"\n";
            list <int>::iterator it;
            for(it=l[tmp].begin();it!=l[tmp].end();it++)
            {
                if(visited[*it]==false)
                {
                    mark[*it]=val(mark[tmp]);
                    visited[*it]=true;
                    q.push_back(*it);
                }
                else if(visited[*it]==true)
                {
                    if(mark[*it]==mark[tmp])
                    {
                        flag=1;
                    }
                }
                if(flag==1)
                    break;
            }
            if(flag==1)
                break;
            q.pop_front();
            if(q.empty()==true)
            {
                for(i=1;i<=n;i++)
                {
                    if(visited[i]==false)
                    {
                        visited[i]=true;
                        mark[i]=1;
                        q.push_back(i);
                       break;
                    }
                }
            }
        }
        printf("Scenario #%d:\n",d);
        if(flag==0)
            printf("No suspicious bugs found!\n");
        else if(flag==1)
            printf("Suspicious bugs found!\n");
        d++;
        }
        return 0;
}
