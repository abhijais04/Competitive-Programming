#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sc(x) scanf("%d",&x)
int tree[1000010],a[1000010],dp[1000010];
unordered_map<int,int> mp;
void update(int idx,int val)
{
    while(idx<=1000001)
    {
        tree[idx]+=val;
        idx+=(idx&-idx);
    }
}
ll getval(int idx)
{
    ll ans=0;
    while(idx>0)
    {
        ans+=tree[idx];
        idx-=(idx&-idx);
    }
    return ans;
}
int main()
{
    int n;
    sc(n);
    for(int i=0;i<n;i++) sc(a[i]);
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        mp[a[i]]++; dp[i]=mp[a[i]];
    }
    mp.clear();
    for(int i=n-1;i>0;i--)
    {
        mp[a[i]]++;
        update(mp[a[i]],1);
        ans+=getval(dp[i-1]-1);
    }
    printf("%lld\n",ans);
	return 0;
}