#include<bits/stdc++.h>
using namespace std;
float ar[1000];
int main()
{
    int i,j,n;
    float sum=0;
    for(n=2;sum<5.20;n++)
    {
        sum+=(1.0/(float)n);
        ar[n-1]=sum;
    }
    while(1)
    {
        float t;
        scanf("%f",&t);
        if(t==0.0)
            break;
        else
        {
            i=1;
            while(t>ar[i])
                i++;
            printf("%d card(s)\n",i);
        }
    }
    return 0;
}
