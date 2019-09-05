#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
ll p[3];
ll a[3];
ll c[3];
ll rr;
bool check(ll mid)
{
    ll need = 0;
    for(int i=0;i<3;i++)
    {
        if(c[i]*mid > a[i])
        need+=(c[i]*mid - a[i])*p[i];
    }
    return need<=rr;
}
int main()
{
    string s;
    cin>>s;
    cin>>a[0]>>a[1]>>a[2];
    cin>>p[0]>>p[1]>>p[2];
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='B') c[0]++;
        else if(s[i]=='S') c[1]++;
        else c[2]++;
    }
    cin>>rr;
    ll l=1,h=1e15;
    while(l<=h)
    {
        ll mid=(l+h)/2;
        if(check(mid))
        {
            l=mid+1;
        }
        else
            h=mid-1;
    }
    cout<<h<<"\n";
}