#include<iostream>
#include<cstdio>
using namespace std;
int n=6000;
int a[6020]={0},sz[6010]={0};
int pf[6010][20],pfn[6010];
void sieve()
{
    int i,j;
    for(i=2;i*i<=n;i++)
    {
        if(a[i]==0)
        {
            for(j=2*i;j<=n;j+=i)
            {
                a[j]=1;
     //           sz[j]++;
            }

        }
    }
    j=1;
    for(i=2;i<=n;i++)
    {
        if(a[i]==0)
            {
                for(j=i;j<=n;j+=i)
                    sz[j]++;
            }
    }
    j=1;
    for(i=2;i<=n;i++)
    {
        if(sz[i]>=3)
            {
                pfn[j]=i;
                j++;
            }
    }
}
int main()
{
    sieve();
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int m;
        scanf("%d",&m);
        printf("%d\n",pfn[m]);
    }
    return 0;
}
