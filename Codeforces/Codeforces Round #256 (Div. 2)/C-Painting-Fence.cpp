#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sc(x) scanf("%d",&x)
int a[100010];
int solve(int l,int r,int pre)
{
    if(r<l) return 0;
    int mn = INT_MAX;
    for(int i=l;i<=r;i++)
        mn = min(mn,a[i]);
    int ans = 0;
    int last = l;
    for(int i=l;i<=r;i++)
        {
            if(a[i]==mn)
            {
                ans+=solve(last,i-1,mn);
                last = i+1;
            }
        }
    if(last<=r)
        ans+=solve(last,r,mn);
    ans += mn-pre;
    ans = min(ans,r-l+1);
    //cout<<l<<" "<<r<<" "<<ans<<"\n";
    return ans;
}
int main()
{
    int n;
    sc(n);
    for(int i=0;i<n;i++) sc(a[i]);
    cout<<solve(0,n-1,0)<<"\n";
    return 0;
}