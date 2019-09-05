#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
string solve(string str)
{
    string ans="";
    int l=str.length();
    int tmp=l-2;
    while(tmp)
    {
        ans = (char)((tmp%10)+'0') + ans;
        tmp/=10;
    }
    ans=str[0]+ans;
    ans+=str[l-1];
    return ans;

}
int main()
{
    int n;
    cin>>n;

    while(n--)
    {
        string str;
        cin>>str;
        if(str.length()<=10)
            cout<<str<<"\n";
        else
            cout<<solve(str)<<"\n";
    }

}