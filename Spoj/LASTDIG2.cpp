#include<iostream>
#include<math.h>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long b;
        char a[1002];
        int ar[10]={0,1,4,4,2,1,1,4,4,2};
        scanf("%s %lld",&a,&b);
        int l=strlen(a);
        l=(a[l-1]-'0');
        l=l%10;
        if(b==0)
            printf("1\n");
        else if(l==0)
            printf("0\n");
        else
        {
            b=b%ar[l];
            if(b==0)
                b=ar[l];
            l=pow(l,b);
            l=l%10;
            printf("%d\n",l);
        }
    }
    return 0;
}
