#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    string str;
    //cin>>t;
    while(cin>>str)
    {

    int i;
    int cnt1=0,cnt2=0;
    //cin>>str;
    for(i=0;i<str.length();i++)
    {
        if(i%2==0)
        {
            if(str[i]>='A'&&str[i]<='Z')
                cnt1++;

        }
        else
        {
            if(str[i]>='a'&&str[i]<='z')
                cnt1++;
        }
    }
    for(i=0;i<str.length();i++)
    {
        if(i%2==1)
        {
            if(str[i]>='A'&&str[i]<='Z')
                cnt2++;

        }
        else
        {
            if(str[i]>='a'&&str[i]<='z')
                cnt2++;
        }
    }
    cout<<min(cnt1,cnt2)<<"\n";
    }
}
