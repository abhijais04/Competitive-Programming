#include <bits/stdc++.h>
using namespace std;
 list <int >l[10001];
 bool visited1[10001],visited2[10001];
 int dis1[10001],dis2[10001];
int main()
{
        int n;
        scanf("%d",&n);
        list <int >l[n+1];
        int i;
        for(i=0;i<n-1;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            l[a].push_back(b);
            l[b].push_back(a);
        }
        visited1[1]=1;
        int mx=0,mxn=1;
        list <int >q;
        q.push_back(1);
        while(!(q.empty()))
        {
            int tmp=q.front();
            list <int>::iterator it;
            for(it=l[tmp].begin();it!=l[tmp].end();it++)
            {
                if(!visited1[*it])
                {
                    visited1[*it]=true;
                    dis1[*it]=dis1[tmp]+1;
                    q.push_back(*it);
                    if(dis1[*it]>mx)
                    {
                        mx=dis1[*it];
                        mxn=*it;
                    }
                }
            }
            q.pop_front();
        }
        q.push_back(mxn);
        mx=0;
        while(!(q.empty()))
        {
            int tmp=q.front();
            list <int>::iterator it;
            for(it=l[tmp].begin();it!=l[tmp].end();it++)
            {
                if(!visited2[*it])
                {
                    visited2[*it]=true;
                    dis2[*it]=dis2[tmp]+1;
                    q.push_back(*it);
                    if(dis2[*it]>mx)
                    {
                        mx=dis2[*it];
                        mxn=*it;
                    }
                }
            }
            q.pop_front();
        }
        printf("%d\n",mx);
        return 0;
}
