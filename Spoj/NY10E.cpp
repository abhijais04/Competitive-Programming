#include <bits/stdc++.h>
using namespace std;
long long dp[100][13];
int main()
{
    long long i,j,k;
    for(i=1;i<65;i++)
    {
        dp[i][0]=1;
    }
    for(i=0;i<10;i++)
    {
        dp[0][i]=0;
    }
    for(i=0;i<10;i++)
    {
        dp[1][i]=1;
    }
    dp[0][0]=0;
    for(i=2;i<66;i++)
    {
        for(j=1;j<10;j++)
        {
            for(k=j;k>=0;k--)
            dp[i][j]+=dp[i-1][k];
        }
    }
    int t;
    cin>>t;
    while(t--)
    {
        long long n,sum=0;
        cin>>n>>k;
        cout<<n<<" ";
        for(i=0;i<10;i++)
            sum+=dp[k][i];
        cout<<sum<<"\n";
    }
    return 0;
}
