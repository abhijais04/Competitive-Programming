#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a;
    scanf("%lld",&a);
    int n=a%10;
    if(n==0)
    {
        printf("2\n");
    }
    else
    {
        printf("1\n%d",n);
    }
    return 0;
}
