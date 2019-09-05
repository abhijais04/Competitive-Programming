#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
ll mx[200010],rmx[200010];
ll sum[200010];
ll a[200010];
int main()
{
    ll n,k;
    cin>>n>>k;
    for(ll i=0;i<n;i++)
    cin>>a[i];
    ll tmx=INT_MIN;
    ll tmp=0;
    for(ll i=0;i<k;i++)
    {
        tmp+=a[i];
    }
    sum[0]=tmp;
    for(ll i=k;i<n;i++)
    {
        tmp+=a[i];
        tmp-=a[i-k];
        sum[i-k+1]=tmp;
    }
    for(ll i=0;i<=n-k;i++)
    {
        if(sum[i]>tmx)
        {
            tmx=a[i];
            mx[i]=i;
        }
        else
            mx[i]=mx[i-1];
    }
    tmx=INT_MIN;
    for(ll i=n-k;i>=0;i--)
    {
        if(sum[i]>=tmx)
        {
            tmx=sum[i];
            rmx[i]=i;
        }
        else
            rmx[i]=rmx[i+1];
    }
    ll aa=0,bb=0;
    tmx=INT_MIN;
    for(ll i=0;i<=n-k;i++)
    {
        ll tsum=sum[i];
        if(i+k<=n-k)
        {
            tsum+=sum[rmx[i+k]];
            if(tsum>tmx)
            {
               // cout<<sum[i]<<" "<<tsum<<" \n";
                aa=i;
                bb=rmx[i+k];
                tmx=tsum;
            }
        }
        else
            continue;

    }
    cout<<aa+1<<" "<<bb+1<<"\n";
}