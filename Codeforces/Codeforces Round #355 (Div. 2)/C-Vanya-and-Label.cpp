#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
ll mod =1000000007;
ll val[63];
int main()
{
    for(int i=0;i<=63;i++)
    {
        for(int j=0;j<=63;j++)
        {
            val[i&j]++;
        }
    }
    string s;
    cin>>s;
    ll ans=1;
    vector <ll>v;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='A'&&s[i]<='Z')
        {
            v.pb((s[i]-'A')+10);
        }
        else if(s[i]>='a'&&s[i]<='z')
        {
            v.pb((s[i]-'a')+36);
        }
        else if(s[i]=='-')
        {
            v.pb(62);
        }
        else if(s[i]=='_')
            v.pb(63);
        else
        {
            v.pb((s[i]-'0'));
        }
        ans=(ans*val[v[i]])%mod;
    }
    cout<<ans<<"\n";
    //int ans=1;
    //for(int i=0;i<v.size();i++)
    //{
   //     cout<<v[i]<<" ";//ans=(ans%mod*val[v[i]]%mod)%mod;
   // }
    return 0;
}