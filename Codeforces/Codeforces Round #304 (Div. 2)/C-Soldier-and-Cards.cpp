#include <bits/stdc++.h>
using namespace std;
#define ll long long
int visited[100010];
map<pair<string,string>,int > mp;
string s1,s2;
int win;
int dfs(int x)
{
    if(mp.count({s1,s2})>0)
        return -1000000;
    //if(visited[x])
     //   return -1000000;
    if(s2.length()==0||s1.length()==0||x==0||(x==win))
        return 0;
    mp[{s1,s2}]++;
    int t1 = s1[s1.length()-1];
    if(s1.length())
    s1.erase(s1.begin()+s1.length()-1);
    int t2 = s2[s2.length()-1];
    if(s2.length())
    s2.erase(s2.begin()+s2.length()-1);
    //s2.pop_back();
    if(t1>t2)
    {
        s1=(char)(t2)+s1;
        s1=(char)(t1)+s1;
       // s1.push_front(t2);
        //s1.push_front(t1);
        x = x|(1<<(t2-1));
    }
    else
    {
        s2=(char)(t1)+s2;
        s2=(char)(t2)+s2;
       // s2.push_front(t1);
        //s2.push_front(t2);
        x = x&(~(1<<(t1-1)));
    }
    return 1+dfs(x);
}
int main(int x)
{
    int n;
    cin>>n;
    win=(1<<n);
    win--;
    int k;
    cin>>k;
    int cst=0;
    int pw;
    for(int i=0;i<k;i++)
    {
        int tmp;
        cin>>tmp;
        s1=(char)(tmp+'0')+s1;
       // s1.push_front(tmp);
        cst = cst|(1<<(tmp-1));
        if(tmp==n)
            pw=1;
    }
    cin>>k;
    for(int i=0;i<k;i++)
    {
        int tmp;
        cin>>tmp;
        s2=(char)(tmp+'0')+s2;
        //s2.push_front(tmp);
        if(tmp==n)
            pw=2;
    }
    int steps = dfs(cst);
    if(steps<0)
        cout<<"-1\n";
    else
        cout<<steps<<" "<<pw<<"\n";
}