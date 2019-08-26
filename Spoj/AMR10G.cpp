#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        long long a[n],i,min=INT_MAX;
        for(i=0;i<n;i++)
        scanf("%lld",&a[i]);
        sort(a,a+n);
        for(i=0;i<n-k+1;i++)
        {
            if(a[i+k-1]-a[i]<min)
            min=a[i+k-1]-a[i];
        }
        printf("%lld\n",min);
    }
    return 0;
}