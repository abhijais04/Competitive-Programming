#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define sc(x) scanf("%d",&x)
int fn(char ch)
{
    if(ch=='T') return 4;
    if(ch=='C') return 6;
    if(ch=='O') return 8;
    if(ch=='D') return 12;
    return 20;
}
int main()
{
    int t;
    sc(t);
    int ans=0;
    while(t--)
    {
        string str;
        cin>>str;
        ans+=fn(str[0]);
    }
    cout<<ans<<"\n";
}