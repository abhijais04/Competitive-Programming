#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
map<int,string> mp;
int main()
{
    mp[1]=mp[0]="";
    mp[2]="2";
    mp[3]="3";
    mp[4]="223";
    mp[5]="5";
    mp[6]="53";
    mp[7]="7";
    mp[8]="2227";
    mp[9]="2337";
    ll t;
    cin>>t;
    ll n;
    cin>>n;
    vector<char> ans;
    while(n)
    {
        string str;
        str=mp[n%10];
        for(int i=0;i<str.length();i++)
            ans.pb(str[i]);
        n/=10;
    }
    int tt = ans.size();
    sort(ans.begin(),ans.end());
    for(int i=tt-1;i>=0;i--)
        cout<<ans[i];
    cout<<"\n";
    return 0;
}