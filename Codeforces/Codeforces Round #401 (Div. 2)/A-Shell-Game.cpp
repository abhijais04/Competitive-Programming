#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int main()
{
    int n;
    cin>>n;
    int p;
    cin>>p;

    n=n%6;
    int ans=0;
    if(n==0)
    {
        ans=p;
        //cout<<p<<"\n";
    }
    else if(n==1)
    {
        if(p==1)
            ans=0;
        else if(p==2)
            ans=2;
        else
            ans=1;
    }
    else if(n==2)
    {
        if(p==0)
            ans=1;
        else if(p==2)
            ans=0;
        else
            ans=2;
    }
    else if(n==3)
    {
        if(p==2)
        {
            ans=0;
        }
        else if(p==1)
        {
            ans=1;
        }
        else
            ans=2;
    }
    else if(n==4)
    {
        if(p==1)
        {
            ans=0;
        }
        else if(p==0)
            ans=2;
        else
        ans=1;
    }
    else if(n==5)
    {
        if(p==0)
            ans=0;
        else if(p==1)
        {
            ans=2;
        }
        else
            ans=1;
    }
    cout<<ans<<"\n";
    return 0;
}