#include<bits/stdc++.h>
using namespace std;
#define pb push_back
map<int,int> mp;
int main()
{
    int a,b;
    cin>>a>>b;
    vector<int> da,db;
    vector<int> cm;
    for(int i=1;i*i<=a;i++)
    {
        if(a%i==0)
            {
                da.pb(i);
                mp[i]++;
                if(i*i!=a)
                {
                    da.pb(a/i);
                    mp[a/i]++;
                }
            }

    }
    for(int i=1;i*i<=b;i++)
    {
        if(b%i==0)
            {
                da.pb(i);
                if(mp.count(i)!=0)
                    cm.push_back(i);
                if(i*i!=b)
                {
                    da.pb(b/i);
                    if(mp.count(b/i)!=0)
                        cm.pb(b/i);
                }
            }

    }
    sort(cm.begin(),cm.end());
    int q;
    cin>>q;
    while(q--)
    {
        int l,u;
        cin>>l>>u;
        int idx=upper_bound(cm.begin(),cm.end(),u)-cm.begin();
        idx--;
        if(idx<0||cm[idx]<l)
            cout<<"-1\n";
        else
            cout<<cm[idx]<<"\n";
    }
}