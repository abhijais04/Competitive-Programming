#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define sc(x) scanf("%lld",&x)
int main()
{
    ll mns1=INT_MAX,mne1=INT_MAX,mxs1=INT_MIN,mxe1=INT_MIN;
    ll mns2=INT_MAX,mne2=INT_MAX,mxs2=INT_MIN,mxe2=INT_MIN;
    ll n,m;
    sc(n);
    while(n--)
    {
        ll l,r;
        sc(l); sc(r);
        mns1 = min(mns1,l);
        mne1 = min(mne1,r);
        mxs1 = max(mxs1,l);
        mxe1 = max(mxe1,r);
    }
    sc(m);
    while(m--)
    {
        ll l,r;
        sc(l); sc(r);
        mns2 = min(mns2,l);
        mne2 = min(mne2,r);
        mxs2 = max(mxs2,l);
        mxe2 = max(mxe2,r);
    }
    ll ans=INT_MIN;
    ans = max(mxs2-mne1,ans);
    ans = max(mxs1-mne2,ans);
    if(ans<=0)
        cout<<"0\n";
    else
    cout<<ans<<"\n";
}