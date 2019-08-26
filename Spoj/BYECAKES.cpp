#include<bits/stdc++.h>
using namespace std;
int main()
{
    while(1)
    {
        int a[9],i;
    for(i=1;i<=8;i++)
    {
        scanf("%d",&a[i]);
    }
    if(a[1]==-1)
        break;
    int mx=0;
    for(i=1;i<=4;i++)
        {
            int tmp;
                tmp=a[i]/a[i+4];
            if(a[i]%a[i+4]!=0)
                tmp++;
            if(tmp>mx)
                mx=tmp;
        }
    for(i=1;i<=4;i++)
    {
        printf("%d ",(a[i+4]*mx)-a[i]);
    }
        printf("\n");
    }
    return 0;
}
