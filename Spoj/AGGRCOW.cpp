#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,c,i;
        scanf("%d%d",&n,&c);
        int a[n];
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        int lo=a[0];
        int hi=a[n-1]+1;
        int mid;
        while(hi-lo>1)
        {
             mid=(hi+lo)/2;
            int lastpo=a[0];
            int co=1;
            for(i=1;i<n;i++)
            {
                if(a[i]-lastpo>=mid)
                {
                    co++;
                    lastpo=a[i];
                    if(co==c)
                        break;
                }
            }
            if(co==c)
                lo=mid;
            else
                hi=mid;
        }
        printf("%d\n",lo);
    }
    return 0;
}
