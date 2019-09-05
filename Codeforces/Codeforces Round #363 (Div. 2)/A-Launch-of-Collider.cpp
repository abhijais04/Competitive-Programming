#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int main()
{
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll a[n],i;
    for(i=0;i<n;i++)
        cin>>a[i];

    ll ci=-1;
    ll mn = 1e9;
    mn++;
    int flag=0;
     i=0;
    while(i<n&&s[i]=='L')
        i++;
    if(i==n)
        flag=0;
    else
    {
        ci = i;
        for(i;i<n;i++)
        {
            if(s[i]=='R')
                ci=i;
            else
            {
                flag=1;
                mn = min(mn,a[i]-a[ci]);
            }
        }
    }
    if(flag==1)
        cout<<mn/2<<"\n";
    else
        cout<<"-1\n";
}