#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
string tostr(int x)
{
    string str = "";
    while(x)
    {
        str = (char)(x%10+'0')+str;
        x=x/10;
    }
    return str;
}
map<string,int> mp;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string str;
        cin>>str;
        if(mp.count(str)!=0)
        {
            int d = mp[str];
            mp[str]++;
            str = str+tostr(d);
            cout<<str<<"\n";
            mp[str]++;
        }
        else
        {
            cout<<"OK\n";
            mp[str]++;
        }
    }
    return 0;
}