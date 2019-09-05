#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sc(x) scanf("%lld",&x)
vector<vector<ll> > ans;
ll a[100010];
vector<ll> even,odd;
int main()
{
    ll n,k,p;
    sc(n); sc(k); sc(p);
    int eneed = p, oneed = k-p;
    for(int i=0;i<n;i++)
    {
        sc(a[i]);
        if(a[i]%2)
            odd.pb(a[i]);
        else
            even.pb(a[i]);
    }
    if((odd.size())%2 != (k-p)%2){cout<<"NO\n"; return 0;}
    if((odd.size()) < k-p) {cout<<"NO\n"; return 0;}

    if(even.size() < p && (odd.size()-(k-p))/2 + even.size() < p) {cout<<"NO\n"; return 0;}

    cout<<"YES\n";

    while(oneed--)
    {
        vector<ll>  tmp;
        tmp.pb(odd[odd.size()-1]);
        odd.pop_back();
        ans.pb(tmp);
    }

    while(odd.size())
    {
        vector<ll>  tmp;
        tmp.pb(odd[odd.size()-1]);
        odd.pop_back();
        //ans.pb(tmp);
        tmp.pb(odd[odd.size()-1]);
        odd.pop_back();
        ans.pb(tmp);
    }
    for(int i=0;i<even.size();i++)
    {
        vector<ll> tmp;
        tmp.pb(even[i]);
        ans.pb(tmp);
    }
    ll sum=0;
    for(int i=0;i<k-1;i++)
    {
        cout<<ans[i].size()<<" ";
        for(int j=0;j<ans[i].size();j++)
            cout<<ans[i][j]<<" ";
        cout<<"\n";
        sum+=(ll)(ans[i].size());
    }

    cout<<n-sum<<" ";
    for(int i=k-1;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
            cout<<ans[i][j]<<" ";
    }
    cout<<"\n";
    return 0;
}