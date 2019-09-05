#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>

using namespace std;
#define pb push_back
int s1[110],s2[110];
int main()
{
    int n;
    cin>>n;
    vector<int> v,v1;
    v.pb(0);
    v1.pb(0);
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        if(x==1)
        v.push_back(y);
        else
        v1.push_back(y);
    }
    sort(v.begin(),v.end());
    sort(v1.begin(),v1.end());
    int ans=INT_MAX;
    int n1=v.size()-1;
    int n2=v1.size()-1;
    for(int i=1;i<=n1;i++)
    {
        s1[i]=s1[i-1]+v[i];
    }
    for(int i=1;i<=n2;i++)
    {
        s2[i]=s2[i-1]+v1[i];
    }
    for(int i=0;i<=n1;i++)
    {
        for(int j=0;j<=n2;j++)
        {
            if(s1[i]+s2[j]<=(n1-i)+2*(n2-j))
            {
                ans=min(ans,(n1-i)+2*(n2-j));
            }
        }
    }
    cout<<ans<<"\n";
}