#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
vector<pair<int,int> > v;
int sd[100010];
int cl[100010];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        v.pb({a,b});
            }
    for(int i=1;i<=n;i++)
    {
            cin>>cl[i];
    }
    int cnt=0;
    for(int i=0;i<v.size();i++)
    {
        int x=v[i].first;
        int y=v[i].second;
        if(cl[x]!=cl[y])
        {
            sd[x]++;
            sd[y]++;
            cnt++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(sd[i]==cnt)
        {
            cout<<"YES\n"<<i<<"\n";
            return 0;
        }
    }
    cout<<"NO\n";
    return 0;
}