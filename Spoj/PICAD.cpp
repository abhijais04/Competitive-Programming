#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int dp[100100];
int main()
{
 //   int t=10;
    ll p,k,n;
    while(scanf("%lld%lld%lld",&p,&k,&n)==3)
    {
        int i;
        p*=2;
        k*=2;
        vector <pair<int,int> >v;
        v.pb({p,0});
        v.pb({k,0});
        for(i=0;i<n;i++)
        {
            int a,b;
            cin>>a>>b;
            a=2*a-1;
            b=2*b+1;
            v.pb({a,+1});
            v.pb({b,-1});
        }
        int mn = n,mx=0;
        int cur=0;
        sort(v.begin(),v.end());
        for(i=0;i<v.size();i++)
        {
            if(v[i].first>=p&&v[i].first<=k)
            {
                mn=min(mn,cur);
                mx=max(mx,cur);
            }
            cur+=v[i].second;
        }
        cout<<mn<<" "<<mx<<"\n";
    }
    return 0;
}
