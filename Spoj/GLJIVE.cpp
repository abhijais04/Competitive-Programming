#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[10];
    int mn=1000000,ans,i,j;
    for(i=0;i<10;i++)
        scanf("%d",&a[i]);
    ans=0;
    for(i=0;i<10;i++)
    {
        ans+=a[i];
        if(ans<100)
        {
            mn=100-ans;
        }
        else
        {
            if(ans-100>mn)
            {
                ans=ans-a[i];
                break;
            }
            break;
        }
    }
    printf("%d\n",ans);
}
