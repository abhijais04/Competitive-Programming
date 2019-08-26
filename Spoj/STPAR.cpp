#include <bits/stdc++.h>
using namespace std;
int main()
{
    while(1)
    {
        int n,c1=0,c2=0,v1=0,v2=-124;
        scanf("%d",&n);
        if(n==0)
            break;
        else
        {
            int a[n],il=0,st[n],z=-1;
            for(int i=0;i<n;i++)
            {
                scanf("%d",&a[i]);
                if(a[i]==il+1)
                    il++;
                else
                {
                    while(1)
                    {
                        if(st[z]==il+1)
                       {
                        z--;
                        il++;
                         if(z<0)
                         break;
                       }
                       else
                        break;
                    }
                    st[++z]=a[i];
                }
            }
                  while(1)
                    {
                        if(st[z]==il+1)
                       {
                        z--;
                        il++;
                         if(z<0)
                         break;
                       }
                       else
                        break;
                    }
             if(il==n)
                printf("yes\n");
             else
                printf("no\n");
        }
    }
    return 0;
}
