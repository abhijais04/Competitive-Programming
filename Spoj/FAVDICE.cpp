#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        double a,ans=0;
        scanf("%lf",&a);
        double i;
        for(i=1;i<=a;i++)
        {
            double tmp=a/i;
            ans+=tmp;
        }
        printf("%.2lf\n",ans);
    }
    return 0;
}
