#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int c1=0,c0=0,i;
    for(i=0;i<s1.length();i++)
    {
        if(s1[i]=='+')
            c1++;
        else
            c0++;
    }
    int n=0,d1=0,d0=0;
    for(i=0;i<s2.length();i++)
    {
        if(s2[i]=='+')
            d1++;
        else if(s2[i]=='-')
            d0++;
        else
            n++;
    }
    double ans=0;
    if(c1<d1||c0<d0)
        cout<<setprecision(12)<<ans<<"\n";
    else
    {
        int tmp=1;
        for(i=1;i<=n;i++)
        {
            tmp*=i;
        }
        for(i=2;i<=c1-d1;i++)
            tmp/=i;
        for(i=2;i<=c0-d0;i++)
            tmp/=i;
        int pw=1;
        for(i=1;i<=n;i++)
            pw*=2;
        //cout<<tmp<<" "<<pw<<"\n";
        ans=(double)tmp/(double)pw;
        cout<<setprecision(12)<<ans<<"\n";
    }
    return 0;
}