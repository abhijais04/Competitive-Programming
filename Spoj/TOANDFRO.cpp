#include<bits/stdc++.h>
using namespace std;
int main()
{
    while(1)
    {
        int cl;
        scanf("%d",&cl);
        if(cl==0)
            break;
        else
        {
            char c[210];
            scanf("%s",&c);
            int l=strlen(c);
            int rows=l/cl;
            char ch[rows][cl+1];
            int i,j;
            for(i=0;i<rows;i++)
            {
                for(j=0;j<cl;j++)
                {
                    ch[i][j]=c[((i)*cl)+j];
                }
            }
           char tmp[cl+1];
            for(i=1;i<rows;i+=2)
            {
                for(j=0;j<cl;j++)
                {
                    tmp[j]=ch[i][cl-j-1];
                }
                tmp[j]='\0';
                for(j=0;j<cl;j++)
                {
                    ch[i][j]=tmp[j];
                }
            }
            for(i=0;i<cl;i++)
            {
                for(j=0;j<rows;j++)
                cout<<ch[j][i];
            }
            cout<<"\n";
        }
    }
    return 0;
}
