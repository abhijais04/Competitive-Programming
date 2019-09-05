#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
struct node
{
    ll a,b,diff;
    bool operator <(node n1)const
    {
        //if(this->diff!=n1.diff)
            return this->diff< n1.diff;

    }

};
ll a[200010],b[200010];

int main()
{
    ll n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
        scanf("%lld",&a[i]);
    for(int i=0;i<n;i++)
        scanf("%lld",&b[i]);
    vector<node> v;
    for(int i=0;i<n;i++)
    {
        node tmp;
        tmp.a=a[i];
        tmp.b=b[i];
        tmp.diff = a[i]-b[i];
        v.pb(tmp);
    }
    sort(v.begin(),v.end());
    ll ans=0;
    for(int i=0;i<k;i++)
        ans+=v[i].a;
    for(int i=k;i<n;i++)
        {
            if(v[i].diff < 0)
                ans+=v[i].a;
            else
                ans+=v[i].b;
        }
    cout<<ans<<"\n";
    return 0;
}