#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long n;
        scanf("%lld",&n);
        n=(n*(n+2)*(n+n+1))/8;
        printf("%lld\n",n);
    }
    return 0;
}
