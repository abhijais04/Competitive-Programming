#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod=1000000007;
int main()
{
    ll n;
    cin>>n;
    ll i,a[n],i1=0,i2=0;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        if(i>0)
        {
            if(a[i]>a[0]&&i1==0)
                i1=i;
            if(a[i]<a[0]&&i2==0)
                i2=i;
        }
    }
    ll mn=1,mn2=1,in=1;
    i=i1;
    while(i<n&&i>0)
    {
        if(in==1)
        {
            ll tmp=a[i];
            while(i<n&&a[i]>=tmp)
            {
                tmp=a[i];
                i++;
            }
            if(i!=n)
            {
                mn++;
                in=-1;
            }
        }
        else
        {
            ll tmp=a[i];
            while(i<n&&a[i]<=tmp)
            {
                tmp=a[i];
                i++;
            }
            if(i!=n)
            {
                in=1;
                mn++;
            }
        }
    }
    //cout<<mn<<"\n";
    i=i2;
    in=-1;
    mn2=1;
    while(i<n&&i>0)
    {
        if(in==1)
        {
            ll tmp=a[i];
            while(i<n&&a[i]>=tmp)
            {
                tmp=a[i];
                i++;
            }
            if(i!=n)
            {
                mn2++;
                in=-1;
            }
            else
                break;

        }
        else
        {
            ll tmp=a[i];
            while(i<n&&a[i]<=tmp)
            {
                tmp=a[i];
                i++;

            }
            if(i!=n)
            {
                in=1;
                mn2++;
            }
        }
    }
   // cout<<mn2<<"\n";
    cout<<max(mn2,mn)+1<<"\n";
}
