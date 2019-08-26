#include<iostream>
#include<cstring>
using namespace std;
static int top=-1;
int prc(char c)
{
    if(c=='+'||c=='-')
        return 1;
    if(c=='*'||c=='/')
        return 2;
    if(c=='^'||c=='$')
        return 3;
}
int main()
{
    int te;
    cin>>te;
    while(te--)
    {
        top=-1;
        char c[410],p[410],st[410];
    cin>>c;
    int l=strlen(c),i,j=0;
    for(i=0;i<l;i++)
    {
        if((c[i]>='a'&&c[i]<='z')||(c[i]>='A'&&c[i]<='Z'))
            {
                p[j++]=c[i];

            }
        else if(c[i]=='(')
        {
            st[++top]=c[i];
        }
        else if(c[i]==')')
        {
            while(st[top]!='(')
            {
                p[j++]=st[top--];
            }
            top--;
        }
        else
        {
            while(prc(st[top])>=prc(c[i])&&top>-1&&st[top]!='(')
            {
                p[j++]=st[top--];
            }
            st[++top]=c[i];
        }
    }
    while(top>-1)
    {
       p[j++]=st[top--];
    }
    for(int i=0;i<j;i++)
        cout<<p[i];
        cout<<"\n";
    }
    return 0;
}