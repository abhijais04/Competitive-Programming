#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    while(b)
    {
        int tmp=a%b;
        a=b;
        b=tmp;
    }
    return a;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        int g=gcd(a,b);
        printf("%d %d\n",b/g,a/g);
    }
    return 0;
}
