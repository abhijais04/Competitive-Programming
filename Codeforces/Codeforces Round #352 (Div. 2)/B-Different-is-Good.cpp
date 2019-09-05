#include <bits/stdc++.h>
using namespace std;
int a[26];
int main()
{
    int l;
    cin>>l;
    string s;
    cin>>s;
    int i;
    for(i=0;i<l;i++)
        a[s[i]-'a']++;
    int c=0;
    for(i=0;i<26;i++)
    {
        if(a[i]>1)
            c+=(a[i]-1);
    }
    if(l>26)
        cout<<"-1";
    else
        cout<<c;
}