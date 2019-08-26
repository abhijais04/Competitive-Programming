#include<bits/stdc++.h>
using namespace std;
int main()
{
    int nq;
    scanf("%d",&nq);
    for(int c=1;c<=nq;c++)
    {
        int n;
        long long tm;
        scanf("%lld%d",&tm,&n);
        long long i,sum=0,a[n];
        for(i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
            sum+=a[i];
        }
        int co=0;
        int flag=1;
        if(tm>sum)
            flag=0;
        else
        {
            flag=1;
            sum=0;
            sort(a,a+n);
            i=n-1;
            co=0;
            while(sum<tm)
            {
                sum+=a[i];
                co++;
                i--;
            }
        }
        printf("Scenario #%d:\n",c);
        if(flag==0)
            printf("impossible\n");
        else
            printf("%d\n",co);
        printf("\n");
    }
    return 0;
}
