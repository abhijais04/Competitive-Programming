#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
ll a[2000010];
int main()
{
    int n;
    scanf("%d",&n);
    ll ans=0;
    for(int i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
            ans+=a[i];
        }
    sort(a+1,a+n+1);
    ll next=1;
    ll tmpsum=0;
    for(int i=n;i>=4;i--)
    {
        tmpsum+=a[i];
        if((n-i+1)==next)
        {
            ans+=tmpsum;
            next*=4;
        }
    }
    printf("%lld\n",ans);
    //cout<<ans<<"\n";
    return 0;
}