#include <bits/stdc++.h>
using namespace std;
vector <int>v[100010];
int dist[100010];
bool visited[100010];
int main()
{
    int n,m,i;
    cin>>n>>m;
    for(i=1;i<=100008;i++)
    {
        if(i!=1)
        v[i].push_back(i-1);
        if(i<10010)
        v[i].push_back(2*i);
    }
    list<int >l;
    l.push_back(n);
    visited[n]=true;
    int flag=0;
    while(!l.empty())
    {
        int tmp=l.front();
        l.pop_front();
       // cout<<tmp<<"\n";
        for(int j=0;j<v[tmp].size();j++)
        {
            if(!visited[v[tmp][j]])
            {
                visited[v[tmp][j]]=true;
                dist[v[tmp][j]]=dist[tmp]+1;
                l.push_back(v[tmp][j]);
            }
            if(visited[m])
                break;
        }
         if(visited[m])
                {
                  //  cout<<"asd\n";
                    break;

                }
    }
    cout<<dist[m]<<"\n";
    return 0;
}