#include<bits/stdc++.h>
using namespace std;
#define ll int
#define pb push_back
vector<ll> v;
int main()
{
    ll n,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        ll tmp;
        scanf("%d",&tmp);
        v.pb(tmp);
    }
    sort(v.begin(),v.end());
    int q;
    scanf("%d",&q);
    while(q--)
    {
        ll qu;
        scanf("%d",&qu);
        int ind = upper_bound(v.begin(),v.end(),qu)-v.begin();
        ind--;
        int ans=0;
        if(ind>=0&&ind<n&&v[ind]<=qu)
            ans=ind+1;
        printf("%d\n",ans);
    }
    return 0;
}