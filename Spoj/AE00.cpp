#include<bits/stdc++.h>
using namespace std;
int dv[10010];
int rec[10010];
void rect()
{
    int i,j;
    for(i=1;i*i<=10000;i++)
    {
        for(j=2*i;j<=10000;j+=i)
        {
            if(i*i<=j)
                dv[j]++;
        }
    }
    dv[1]=1;
    for(i=1;i<=10000;i++)
        rec[i]=rec[i-1]+dv[i];
}
int main()
{
        rect();
        int n;
        scanf("%d",&n);
        printf("%d\n",rec[n]);
}
