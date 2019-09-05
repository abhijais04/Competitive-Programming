#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i;
    cin>>n;
    map <int,int>mp;
    map <int,int>::iterator l,r,s;
    mp[0]=0;
    mp[(1e9)+4]=0;
    for(i=0;i<n;i++)
    {
        int x;
        cin>>x;
         l = mp.lower_bound(x);
         r=l;
        l--;
        //a s;
        if(r->second>l->second)
            s=r;
        else
        s=l;
        if(i)
        cout<<s->first<<" ";
        mp[x]=s->second+1;
    }
    return 0;
}