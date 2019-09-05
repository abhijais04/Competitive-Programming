# include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
bool allz(string s)
{
    int l=s.length();
    for(int i=0;i<l;i++)
    {
        if(s[i]!='0')
            return false;
    }
    return true;
}
bool allo(string s)
{
    int l=s.length();
    for(int i=0;i<l;i++)
    {
        if(s[i]!='1')
            return false;
    }
    return true;
}
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int l1=s1.length();
    int l2=s2.length();

    if(s1==s2)
    {
        cout<<"YES\n";
        return 0;
    }
    if(l1!=l2)
    {
        cout<<"NO\n";
        return 0;
    }
    if((allz(s1)&&!allz(s2))||(!allz(s1)&&allz(s2)))
    {
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    return 0;
}