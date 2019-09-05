#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int dp[510][3];
int main()
{
    int n;
    cin>>n;
    int x=0,y=0,z=0;
    while(n--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        x+=a;
        y+=b;
        z+=c;
    }
    if(x==0&&y==0&&z==0)
        cout<<"YES\n";
    else
        cout<<"NO\n";
}