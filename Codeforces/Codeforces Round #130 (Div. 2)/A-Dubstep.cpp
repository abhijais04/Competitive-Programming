#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int main()
{
    string str;
    cin>>str;
    int l=str.length();
    int flag=1;
    if(l<3)
    {
        cout<<str<<"\n";
        return 0;
    }
    int i;
    for(i=0;i<l-3;)
    {

        string tmp="";
        for(int j=i;j<i+3;j++)
        {
            tmp+=str[j];
        }
        if(tmp=="WUB")
        {
            if(flag==0)
            {
                cout<<" ";
                flag=1;
            }
            i+=3;
        }
        else
        {
            flag=0;
            cout<<str[i];
            i++;
        }
    }
    string tmp="";
    for(int j=i;j<l;j++)
        {
            tmp+=str[j];
        }
    if(tmp!="WUB")
       cout<<tmp<<"\n";
    return 0;
}