#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char ch[15];
        scanf("%s",&ch);
        int l=strlen(ch);
        int i,flag=1,j,k;
        if(l%2==1)
        {
            for(i=1;i<=(l/2);i++)
            {
                if(ch[(l/2)+i]!=ch[(l/2)-i])
                {
                flag=0;
                break;
                }
            }
        }
        else
        {
            i=l/2;
            int j=l/2-1;
            for(k=0;k<l/2;k++)
            {
                if(ch[j-k]!=ch[i+k])
                {
                    flag=0;
                    break;
                }
            }
        }
        if(flag==1)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
