#include <bits/stdc++.h>
using namespace std;
int main()
{
   // int t;
    string str;
    int cnt =1;
    //cin>>t;
    while(cin>>str)
    {

    int i;
    int cnt1=0,ans;

    //cin>>str;
    for(i=0;i<str.length();i++)
    {
        if((str[i]-'0')==1)
        {
            if(cnt1%2==0)
            {
                cnt1++;
            }
        }
        else
        {
            if(cnt1%2==1)
            {
                cnt1++;
            }
        }
    }
    cout<<"Game #"<<cnt++<<": ";
    cout<<cnt1<<"\n";
    }
    return 0;
}
