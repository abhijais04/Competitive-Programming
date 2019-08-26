#include <bits/stdc++.h>
using namespace std;
int main()
{
    char ch[300];
    while(scanf("%s",&ch)!=EOF)
    {
        int l=strlen(ch);
        int c=0,java=0,err=0;
        if((ch[0]>='A'&&ch[0]<='Z')||ch[l-1]=='_'||ch[0]=='_')
        err=1;
        int i;
        for(i=0;i<l;i++)
        {
            if(ch[i]>='A'&&ch[i]<='Z')
            {
                java=1;
            }
            else if(ch[i]=='_')
            {
                c=1;
                if(i<l-1)
                {
                    if((ch[i+1]<='Z'&&ch[i+1]>='A')||(ch[i+1]=='_'))
                    err=1;
                }
                else
                err=1;
            }
        }
        if((java==1&&c==1)||err==1)
        printf("Error!\n");
        else
        {
            if(java==0&&c==0)
            printf("%s\n",ch);
            else
            {
                if(java==1)
                {
                    for(i=0;i<l;i++)
                    {
                        if(ch[i]>='A'&&ch[i]<='Z')
                        {
                            int j;
                            for( j=l;j>i;j--)
                            ch[j]=ch[j-1];
                            ch[j]='_';
                            l++;
                            ch[i+1]+=32;
                            
                        }
                    }
                }
                else if(c==1)
                {
                    for(i=0;i<l;i++)
                    {
                        if(ch[i]=='_')
                        {
                            int j;
                            for(j=i;j<l;j++)
                            ch[j]=ch[j+1];
                            ch[i]-=32;
                            l--;
                            
                        }
                    }
                }
                for(i=0;i<l;i++)
                printf("%c",ch[i]);
                printf("\n");
            }
        }
    }
    return 0;
}