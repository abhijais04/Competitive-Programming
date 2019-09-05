#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
int cnt[1010];
int main()
{
    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int a,b;
        cin>>a>>b;
 //       e[a][b]=e[b][a]=-1;
        cnt[a]++;
        cnt[b]++;
    }
    int tmp=0;
    int mn=1000000;
    for(int i=1;i<=n;i++)
        if(cnt[i]<mn)
            mn=cnt[i],tmp=i;
    //ans+=(n-cnt[tmp]);
    //ans=n-1;
    cout<<n-1<<"\n";
    for(int i=1;i<=n;i++)
    {
        if(i!=tmp)
            cout<<tmp<<" "<<i<<"\n";
    }
    return 0;
}