#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,i;
    scanf("%d%d",&n,&k);
    int a[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int ans=0;
    sort(a,a+n);
    for(i=0;a[i]+k<=a[n-1];i++)
    {
        ans+=(upper_bound(a,a+n,a[i]+k)-lower_bound(a,a+n,a[i]+k));
    }
    cout<<ans<<"\n";
}
