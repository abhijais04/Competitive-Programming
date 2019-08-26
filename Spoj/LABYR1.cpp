#include <bits/stdc++.h>
using namespace std;
int mt[1001][1001];
char ch[1000][1001];
 list <int>l[1000001];
list <int >q;
 list<int>::iterator it;
int main()
{
	q.clear();
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,i,j;
        scanf("%d%d",&m,&n);
        for(i=0;i<n;i++)
            scanf("%s",&ch[i]);
        int c=1;
        for(i=0;i<=n;i++)
        {
            for(j=0;j<=m;j++)
            {
                if(i>n-1||j>m-1)
                    mt[i][j]=0;
                else if(ch[i][j]=='.')
                {
                    mt[i][j]=c;
                    c++;
                }
                else
                {
                    mt[i][j]=0;
                }
            }
        }
        //cout<<"dgsd\n";

       for(i=1;i<=c;i++)
        l[i].clear();
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {

                if(ch[i][j]=='.')
                {
                    int a=mt[i][j];

                    if(mt[i+1][j]!=0)
                    {
                        l[a].push_back(mt[i+1][j]);
                    }
                    if(i>0)
                    {
                        if(mt[i-1][j]!=0)
                    {
                        l[a].push_back(mt[i-1][j]);
                    }
                    }
                    if(mt[i][j+1]!=0)
                    {
                        l[a].push_back(mt[i][j+1]);
                    }
                    if(j>0)
                    {
                        if(mt[i][j-1]!=0)
                        {
                        l[a].push_back(mt[i][j-1]);
                        }
                    }
                }
            }

        }

        bool visited1[c],visited2[c];
        int d1[c+1],d2[c+1];
        for(i=1;i<=c;i++)
        {
            visited1[i]=visited2[i]=false;
            d1[i]=d2[i]=0;
        }
        visited1[1]=true;
        q.push_back(1);
        int mx=0;
        int mxn=1;
        while(!(q.empty()))
        {
            int tmp=q.front();

            for(it=l[tmp].begin();it!=l[tmp].end();it++)
            {
                if(!visited1[*it])
                {
                    visited1[*it]=true;
                    d1[*it]=d1[tmp]+1;
                    q.push_back(*it);
                }
                if(d1[*it]>mx)
                {
                    mx=d1[*it];
                    mxn=*it;
                }
            }
            q.pop_front();
        }
        q.push_back(mxn);
        mx=0;
        visited2[mxn]=true;
        d2[mxn]=0;
        while(!(q.empty()))
        {
            int tmp=q.front();
            list <int>::iterator it;
            for(it=l[tmp].begin();it!=l[tmp].end();it++)
            {
                if(!visited2[*it])
                {
                    visited2[*it]=true;
                    d2[*it]=d2[tmp]+1;
                    q.push_back(*it);
                }
                if(d2[*it]>mx)
                {
                    mx=d2[*it];
                    mxn=*it;
                }
            }
            q.pop_front();
        }
        printf("Maximum rope length is %d.\n",mx);
    }
    return 0;
}
