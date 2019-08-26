#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[1002][1002];
ll a[1010],n;
ll fn(ll i,ll j)
{
    if(i>j)
        return 0;
    if(dp[i][j]!=0)
        return dp[i][j];
    if((n+i-j)%2==0)
    {
        if(a[i]<a[j])
            return fn(i,j-1);
        else
            return fn(i+1,j);
    }
    return dp[i][j]=max(a[i]+fn(i+1,j),fn(i,j-1)+a[j]);
}
int main()
{
    int cnt=1;
    while(1)
    {
        cin>>n;
        if(n==0)
            break;
        ll i,j;
        for(i=0;i<=n;i++)
        {
            for(j=0;j<=n;j++)
                dp[i][j]=0;
        }
        ll sum=0;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
        cout<<"In game "<<cnt++<<", the greedy strategy might lose by as many as "<<2*fn(0,n-1)-(sum)<<" points.\n";
        //cout<<2*fn(0,n-1)-(sum)<<"\n";
    }
    return 0;
}
