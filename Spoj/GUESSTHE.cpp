#include <bits/stdc++.h>
using namespace std;
unsigned long long lcm(unsigned long long a,unsigned long long b)
{
   unsigned long long ans=1;
   unsigned long long a1=a,b1=b;
    while(b)
    {
        long long temp=a%b;
        a=b;
        b=temp;
    }
    a1=a1/a;
    a1=a1*b1;
    return a1;
}
int main()
{
    while(1)
    {
        char ch[25];
        scanf("%s",&ch);
        if(ch[0]=='*')
            break;
       unsigned long long i=0;
       unsigned long long l=strlen(ch),f;
        while(ch[i]!='Y'&&i<l)
            i++;
        int flag=1;
        if(i==l)
        {
            flag=0;
        }
        else
            f=i+1;
        i++;
        while(i<l)
        {
            if(ch[i]=='Y')
                f=lcm(f,i+1);
            i++;
        }
        i=0;
        while(i<l)
        {
            if(ch[i]=='N'&&f%(i+1)==0)
            {
                flag=0;
                break;
            }
            i++;
        }
        if(flag==0)
            printf("-1\n");
        else
            printf("%u\n",f);

    }
    return 0;
}
