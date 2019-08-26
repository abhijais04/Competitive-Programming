#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod=1000000007;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n],i;
        ll sum[n];
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            sum[i]=a[i];
            if(i>0)
                sum[i]+=sum[i-1];

        }
      /*  for(i=0;i<n;i++)
        {
             cout<<sum[i]<<" ";
        }
        *///cout<<"\n";
        ll ans=0;
        for(i=n-1;i>0;i--)
        {
           // cout<<"ans before : "<<ans<<"\n";
           // cout<<(i*a[i])<<" - "<<sum[i-1]<<" = ";
           // cout<<((i*(a[i]))-sum[i-1])<<" \n";
            ans=ans+(i*a[i])-sum[i-1];
           // cout<<"ans after : "<<ans<<"\n";
        }
        cout<<ans<<"\n";
    }
    return 0;
}
