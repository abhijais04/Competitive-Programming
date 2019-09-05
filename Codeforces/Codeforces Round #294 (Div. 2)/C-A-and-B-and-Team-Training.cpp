#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
map<int,string> mp;
int main()
{
    int n,m;
    cin>>n>>m;
    int teams=0;
    int mx=0;
    for(int i=0;i<=n/2&&i<=m;i++)
    {
        int tmp = i+min(n-2*i,(m-i)/2);
        mx=max(mx,tmp);
    }
    for(int i=0;i<=m/2&&i<=n;i++)
    {
        int tmp = i+min(m-2*i,(n-i)/2);
        mx=max(tmp,mx);
    }
    cout<<mx<<"\n";
    return 0;
}