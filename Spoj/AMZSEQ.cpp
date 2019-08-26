#include <bits/stdc++.h>
using namespace std;
int dp[10000][5];
int n;
int fn(int l,int pre)
{
    if(l>n)
    return 0;
    if(dp[l][pre]!=0)
        return dp[l][pre];
    if(l==n)
    {
        if(pre==0||pre==2)
            return 2;
        if(pre==1)
            return 3;
    }
    if(pre==0)
    {
        return dp[l][pre]=fn(l+1,1)+fn(l+1,0);
    }
    if(pre==1)
    {
        return dp[l][pre]=fn(l+1,1)+fn(l+1,2)+fn(l+1,0);
    }
    else
        return dp[l][pre]=fn(l+1,2)+fn(l+1,1);
}
int main()
{
    //int n;
    cin>>n;
    if(n==1)
        cout<<"3\n";
    else
    cout<<fn(2,0)+fn(2,1)+fn(2,2)<<"\n";
}
