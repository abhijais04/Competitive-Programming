#include <bits/stdc++.h>
using namespace std;
long long im(long long a,long long p)
{
    long long b=p-2;
    long long ans=1;
    while(b>0)
    {
        if(b&1)
        {
            ans=(ans*a)%p;
        }
        a=(a*a)%p;
        b=b/2;
    }
    return ans;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long n,p,ans=0;
        scanf("%lld%lld",&n,&p);
        if(n>=p)
            ans=0;
        else
        {
            ans=p-1;
            long long tmp=p-1;
            for(long long i=p-1;i>n;i--)
            {
                tmp=(tmp*im(i,p))%p;
            }
            ans=tmp;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
