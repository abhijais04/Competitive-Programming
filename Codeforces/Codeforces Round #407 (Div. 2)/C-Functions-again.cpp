#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sc(x) scanf("%lld",&x)
ll ar[100010];
ll diff[100010];
ll diff2[100010];
ll msum(ll a[], ll sz)
{
    ll max_so_far = 0, max_ending_here = 0;
   for (int i = 0; i < sz; i++)
   {
       max_ending_here = max_ending_here + a[i];
       if (max_ending_here < 0)
           max_ending_here = 0;
       else if (max_so_far < max_ending_here)
           max_so_far = max_ending_here;
   }
   return max_so_far;
}
int main()
{
    ll n;
    sc(n);
    for(int i=0;i<n;i++)
    {
        sc(ar[i]);
    }

    for(int i=0;i<n-1;i++)
    {
        diff[i] = abs(ar[i]-ar[i+1]);
        diff2[i] = diff[i];
        if(i&1)
            diff[i] = -1*diff[i];
        else
            diff2[i] = -1*diff2[i];
    }
    n--;
    ll ans = max(msum(diff,n),msum(diff2,n));
    cout<<ans<<"\n";
}