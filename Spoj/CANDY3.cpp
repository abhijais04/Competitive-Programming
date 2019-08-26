#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long t;
    scanf("%lld",&t);
    while(t--)
    {
        long long a,sum=0,z;
        scanf("%lld",&a);
        z=a;
        while(a--)
        {
            long long n;
            scanf("%lld",&n);
            sum=(sum%z)+(n%z);
            sum%=z;
        }
        if(sum==0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
