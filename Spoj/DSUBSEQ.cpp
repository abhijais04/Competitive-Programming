#include <bits/stdc++.h>
using namespace std;
long long dp[2000010];
long long m=1000000007;
string str;
long long fn(long long x)
{
    long long i;
    for(i=x-1;i>=0;i--)
    {
        if(str[i]==str[x])
            return dp[i];
    }
    return 0;
}
int main()
{
    long long t,i;
    dp[0]=1;
    dp[1]=2;
    cin>>t;
    while(t--)
    {
       // string str;
        cin>>str;
        long long n=str.length();
        for(i=2;i<=n;i++)
        {
            //cout<<
            dp[i]=((dp[i-1]%m+dp[i-1]%m)%m-fn(i-1)%m)%m;
            if(dp[i]<0)
                dp[i]+=m;
        }
        //for(i=0;i<=n;i++)
          //  cout<<dp[i]<<" "<<i<<" "<<str[i]<<" "<<fn(i)<<"\n";
        cout<<dp[n]<<" ";
      //  cout<<"\n";
    }

}
