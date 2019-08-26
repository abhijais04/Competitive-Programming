#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n1,n2,i,j;
        scanf("%d",&n1);
        long long a1[n1];
        for(i=0;i<n1;i++)
            scanf("%lld",&a1[i]);
        scanf("%d",&n2);
        long long a2[n2];
        for(i=0;i<n2;i++)
            scanf("%lld",&a2[i]);
        sort(a1,a1+n1);
        sort(a2,a2+n2);
        long long mn=INT_MAX;
        long long pre,diff;
        for(i=0;i<n1;i++)
        {
            pre=a1[i]-a2[0];
            if(pre<0)
                pre=-pre;
            for(j=0;j<n2;j++)
            {
                diff=a1[i]-a2[j];
                if(diff<0)
                    diff=-diff;
                if(diff>pre)
                    break;
                else
                    pre=diff;
                if(diff<mn)
                    mn=diff;
            }
        }
        printf("%lld\n",mn);
    }
    return 0;
}
