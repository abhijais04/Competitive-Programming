#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t=10;
    while(t--)
    {
        char ch1[130],ch2[130];
    cin>>ch1;
    cin>>ch2;
    int a1[130],a2[130],s[130],m[130],c=0;
    int l1=strlen(ch1),l2=strlen(ch2);
    int i;
    for(i=0;i<l1;i++)
        a1[i]=ch1[l1-1-i]-'0';
    for(i=0;i<l2;i++)
        a2[i]=ch2[l2-1-i]-'0';
        i=0;
        int b=0;
    while(i<l1)
    {
        if(i<l2)
        m[i]=a1[i]-b-a2[i];
        else
            m[i]=a1[i]-b;
            b=0;
        if(m[i]<0)
        {
            m[i]=m[i]+10;
            b=1;
        }
        i++;
    }
    int lm=i;
    while(m[lm-1]==0&&lm>1)
        lm--;
    for(i=lm-1;i>=0;i--)
    {
        m[i]=(m[i]+(b*10));
        b=m[i]%2;
        m[i]=m[i]/2;
    }
    while(m[lm-1]==0&&lm>1)
        lm--;
        c=0;
        i=0;
      while(i<lm||i<l2)
    {
        if(i>=lm)
        {
            s[i]=(a2[i]+c)%10;
        c=(a2[i]+c)/10;
        }
        else if(i>=l2)
        {
            s[i]=(m[i]+c)%10;
        c=(m[i]+c)/10;
        }
        else
        {
            s[i]=(m[i]+a2[i]+c)%10;
            c=(m[i]+a2[i]+c)/10;
        }
        i++;
    }
    while(c!=0)
    {
        s[i]=c%10;
        c=c/10;
        i++;
    }
    int lsm=i;
    for(i=lsm-1;i>=0;i--)
    {
        cout<<s[i];
    }
    cout<<"\n";
    for(i=lm-1;i>=0;i--)
        cout<<m[i];
        cout<<"\n";
    }
    return 0;
}
