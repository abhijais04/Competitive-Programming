#include <bits/stdc++.h>
using namespace std;
int main()
{
    while(1)
    {
        int n;
        scanf("%d",&n);
        if(n==0)
            break;
        else
        {
            int ar[n+1],i;
            for(i=1;i<=n;i++)
                scanf("%d",&ar[i]);
            int flag=0;
            for(i=1;i<=n;i++)
            {
                if(ar[ar[i]]==i)
                    flag=1;
                else
                {
                    flag=0;
                    break;
                }
            }
            if(flag==0)
                printf("not ambiguous\n");
            else
                printf("ambiguous\n");
        }
    }
    return 0;
}
