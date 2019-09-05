#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int ans[100100],tmp[100100];
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n+1][m+1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    }
    for(int i=1;i<=m;i++)
        tmp[i]=n;
    ans[n]=n;
    for(int i=n-1;i>=1;i--)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j] > a[i+1][j])
            {
                tmp[j]=i;
            }
            ans[i]=max(ans[i],tmp[j]);
        }
    }
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int l,r;
        cin>>l>>r;
        if(ans[l]>=r)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;

}