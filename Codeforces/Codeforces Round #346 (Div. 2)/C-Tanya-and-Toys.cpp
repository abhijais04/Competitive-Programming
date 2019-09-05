#include <bits/stdc++.h>
using namespace std;
map <int ,int>mp;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    //vector < node>v[m+1];
    while(n--)
    {
        int tmp;
        cin>>tmp;
        mp[tmp]++;
    }
    int i=1;
    vector <int>v;
    while(m>0)
    {
        if(m-i>=0)
        {
            if(mp.count(i)==0)
            {
                v.push_back(i);
                m=m-i;
                i++;
            }
            else
                i++;
        }
        else
            break;
    }
    cout<<v.size()<<"\n";
    if(v.size()>0)
    {
        for(i=0;i<v.size();i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}