#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    int z=0;
    while(t--)
    {
        string ch;
        if(z==0)
        {
            getline(cin,ch);
            z=1;
        }
        getline(cin,ch);
        getline(cin,ch);
        int l=ch.length();
        int i=0,a=0,b=0,c=0;
           while(ch[i]!='+')
           {
               if(ch[i]>='0'&&ch[i]<='9')
               {
                   a=(a*10)+(ch[i]-'0');
               }
               else if(ch[i]=='m')
               {
                   a=-1;
                   break;
               }
               i++;
           }
           while(ch[i]!='+')
            i++;
           i++;
           while(ch[i]!='=')
           {
               if(ch[i]>='0'&&ch[i]<='9')
               {
                   b=(b*10)+(ch[i]-'0');
               }
               else if(ch[i]=='m')
               {
                   b=-1;
                   break;
               }
               i++;
           }
           while(ch[i]!='=')
            i++;
           i++;
           while(i<l)
           {
               if(ch[i]>='0'&&ch[i]<='9')
               {
                   c=(c*10)+(ch[i]-'0');
               }
               else if(ch[i]=='m')
               {
                   c=-1;
                   break;
               }
               i++;
           }
           if(a==-1)
            a=c-b;
           if(b==-1)
            b=c-a;
           if(c==-1)
            c=a+b;
           printf("%d + %d = %d\n",a,b,c);
    }
    return 0;
}
