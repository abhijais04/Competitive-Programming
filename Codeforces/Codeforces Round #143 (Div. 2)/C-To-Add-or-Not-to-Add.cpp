#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
ll a[100100];
int main()
{
    ll n,k;
    cin>>n>>k;
    for(ll i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    ll l=0,r=0,sum=0,mx=0,imx=0;
    for(ll i=0;i<n;i++)
    {
        r=i;
        sum+=a[i];
        ll need = (r-l+1)*a[i] - sum;
       // cout<<i<<" "<<l<<" "<<need<<" \n";
        while(need>k)
        {
            sum-=a[l];

            l++;
            need = (r-l+1)*a[i] - sum;
        }
       // cout<<i<<" "<<l<<" "<<need<<" \n";
        if(r-l+1>mx)
        {
            mx=(r-l+1);
            imx=a[i];
        }
    }
    cout<<mx<<" "<<imx<<"\n";

}