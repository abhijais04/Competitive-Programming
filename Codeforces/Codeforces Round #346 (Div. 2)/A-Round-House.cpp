#include <bits/stdc++.h>
using namespace std;
int pr(int a,int n)
{
    if(a>1)
        return a-1;
    if(a==1)
        return n;
}
int nx(int a,int n)
{
    if(a<n)
        return a+1;
    if(a==n)
        return 1;
}
int main()
{
    //while(1)
    {
        int a,b,n;
    cin>>n>>a>>b;
    if(b<0)
    {
        b=-b;
        b=b%n;
        int ans=a;
        while(b--)
        {
            ans=pr(ans,n);
        }
        cout<<ans<<"\n";
    }
    else
    {
        //b=-b;
        b=b%n;
        int ans=a;
        while(b--)
        {
            ans=nx(ans,n);
        }
        cout<<ans<<"\n";
    }
    }
    return 0;
}