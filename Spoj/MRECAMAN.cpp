#include <bits/stdc++.h>
using namespace std;
long long a[500011];
bool b[5000010];
int main()
{
    b[0]=true;
    int i;
    for(i=1;i<=500000;i++)
    {
        if(a[i-1]>i)
        {
            if(b[a[i-1]-i]==true)
                a[i]=a[i-1]+i;
            else
                a[i]=a[i-1]-i;
        }
        else
            a[i]=a[i-1]+i;
        b[a[i]]=true;
    }
    while(1)
    {
        int k;
        scanf("%d",&k);
        if(k==-1)
            break;
        else
            printf("%lld\n",a[k]);
    }
    return 0;
}
