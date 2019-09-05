#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int cnt(int x)
{
    int cntt=0;
    while(x)
    {
        x = x&(x-1);
        cntt++;
    }
    return cntt;
}
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    int a[m+1];
    for(int i=0;i<=m;i++)
    {
        cin>>a[i];
    }
    int ans=0;
    for(int i=0;i<m;i++)
    {
        if(cnt(a[i]^a[m])<=k)
            ans++;
    }
    cout<<ans<<"\n";
    return 0;
}