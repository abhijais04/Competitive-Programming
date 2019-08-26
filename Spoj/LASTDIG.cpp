#include<iostream>
#include<math.h>
#include<cstdio>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long b;
        int a,ar[10]={0,1,4,4,2,1,1,4,4,2};
        scanf("%d%lld",&a,&b);
        a=a%10;
        if(b==0)
            printf("1\n");
        else if(a==0)
            printf("0\n");
        else
        {
            b=b%ar[a];
            if(b==0)
                b=ar[a];
            a=pow(a,b);
            a=a%10;
            printf("%d\n",a);
        }
    }
    return 0;
}
