#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int r[110],c[110],g[110];
int a[110],b[110];
int main()
{
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        int tmp;
        cin>>tmp;
        if(1&(tmp))
        {
            a[i]=1;//contest
        }
        if(2&tmp)
        {
            b[i]=1;
        }
    }
    //int ans[n];
    if(a[0]==1)
        {
            c[0]=1;
           // ans[0]=1;
        }
    if(b[0]==1)
        {
            g[0]=1;
           // ans[0]=1;
        }
    if(a[1]==1)
    {
        if(g[0]==1)
            c[1]=2;
        else
            c[1]=1;
    }
    else
        c[1]=c[0];
    if(b[1]==1)
    {
        if(c[0]==1)
            g[1]=2;
        else
            g[1]=1;
    }
    else
        g[1]=g[0];
    for(i=2;i<n;i++)
    {
        if(a[i]==1)
        {
            c[i]=max(1+g[i-1],1+c[i-2]);
        }
        else
            c[i]=c[i-1];
        if(b[i]==1)
        {
            g[i]=max(1+c[i-1],1+g[i-2]);
        }
        else
            g[i]=g[i-1];
    }

    int ans=max(c[n-1],g[n-1]);

    cout<<n-ans<<"\n";


}