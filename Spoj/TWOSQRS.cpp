#include <bits/stdc++.h>
using namespace std;
long long a[1000010];
int main()
{
    long long i;
    for(i=0;i<=1000000;i++)
    {
        a[i]=i*i;
    }
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long n;
        scanf("%lld",&n);
        int flag=0;
        for(i=0;i*i<=n;i++)
        {
            long long tmp;
            tmp=sqrt(n-a[i]);
            if(tmp*tmp==(n-a[i]))
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
