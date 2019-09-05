#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int main()
{
   // while(1)
    {
        ll a[3];
    cin>>a[0]>>a[1]>>a[2];
    int mi = 0;
    ll mx=0;
    for(int i=0;i<3;i++)
    {
        if(a[i]>=mx)
        {
            mx=a[i];
            mi=i;
        }
    }
    ll ans=0;
    ans = max(ans,abs(a[mi]-a[(mi+1)%3])-1);
    ans += max((ll)0,abs(a[mi]-a[(mi+2)%3])-1);
    cout<<ans<<"\n";
    }
    return 0;
}