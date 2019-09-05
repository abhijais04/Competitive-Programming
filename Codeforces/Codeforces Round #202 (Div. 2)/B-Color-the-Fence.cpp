#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
ll a[12];
ll n;
ll get(ll idx,ll val)
{
    for(int i=9;i>=idx;i--)
    {
        if(a[i]<=val)
            return i;
    }
    return idx-1;
}
int main()
{
    cin>>n;
    int mnvl=INT_MAX,idx=0;

    for(int i=1;i<=9;i++)
    {
        cin>>a[i];
        if(a[i]<=mnvl)
        {
            idx=i;
            mnvl=a[i];
        }
    }
    if(mnvl>n)
    {
        cout<<"-1\n";
        return 0;
    }
    else
    {
        ll cnt=n/a[idx];
        ll left=n;
        for(int i=0;i<cnt;i++)
        {
            for(int j=9;j>=1;j--)
            {
                if((left-a[j])/a[idx]==cnt-1-i&&a[j]<=left)
                {
                    cout<<j;
                    left-=a[j];
                    break;
                }
            }
        }
        cout<<"\n";
    }
    return 0;

}