#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int dp[1010];
int main()
{
    string str;
    cin>>str;
    int l=str.length();
    int mx=0;
    for(int i=0;i<l;i++)
    {
        if(str[i]=='h')
        {
            dp[i]=1;
        }
        else if(str[i]=='e')
        {
            if(mx==1)
                dp[i]=2;
        }
        else if(str[i]=='l')
        {
            if(mx==2)
                dp[i]=3;
            else if(mx==3)
                dp[i]=4;
        }
        else if(str[i]=='o')
        {
            if(mx==4)
                dp[i]=5;
        }
        mx=max(mx,dp[i]);
        if(mx==5)
        {
            cout<<"YES\n";
            return 0;
        }
    }
    cout<<"NO\n";
    return 0;
}