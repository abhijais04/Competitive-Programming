#include <iostream>
#include<cstdio>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    char ch[2][3]={"LL","RR"};
    char ch2[2][3]={"UD","UD"};
    while(t--)
    {
        long long n,m;
        scanf("%lld%lld",&n,&m);
         if(n<=m)
        printf("%c\n",ch[n&1][m&1]);
        else if(m<n)
        {
            printf("%c\n",ch2[n&1][m&1]);
        }
    }
    return 0;
}
