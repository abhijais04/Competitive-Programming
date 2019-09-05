#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define ll long long
#define mp make_pair
#define pp pair<ll,ll>
int main()
{
    string s;
    cin>>s;
    ll n = s.length();
    int l=-1,r=-1,i,j;
    for(i=0;i<n;i++)
    {
        if(s[i]!='a')
        {
            l=i;
            break;
        }
    }
    if(i==n)
    {
     //   cout<<"an\n";
        l=n-1;
        r=n-1;
    }
    else
    {
        for(j=i+1;j<n;j++)
        {
            if(s[j]=='a')
            {
                r=j-1;
                break;
            }
        }
        if(j==n)
        {
            r=n-1;
        }
    }
    for(i=l;i<=r;i++)
        {
            if(s[i]>'a')
                s[i]=s[i]-1;
            else
                s[i]='z';
        }
    cout<<s<<"\n";
}