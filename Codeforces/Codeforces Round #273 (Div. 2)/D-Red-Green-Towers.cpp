#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int m = 1e9+7;
vector<int> dp(200002,0);
int main()
{
    int r,g;
    cin>>r>>g;
    int h=0;
    while((h*(h+1))/2 <=(r+g))
    {
        h++;
    }
    h--;
    if(g<r)
    {
        int tmp = r;
        r = g;
        g = tmp;
    }
    dp[1]=1;
    dp[0]=1;
    for(int i=2;i<=h;i++)
    {
        vector<int> ndp(r+1,0);
        int mx = i*(i+1)/2;
        for(int j=0;j<=r;j++){
            if(j>=i)
            {
                ndp[j] += dp[j-i];
                ndp[j]%=m;
            }
            if(mx-j >= i)
            {
                ndp[j] += dp[j];
                ndp[j] %= m;
            }
        }
        dp = ndp;
    }
    ll ans = 0;
    for(int i=0; i <=r ;i++)
    {
        if((h*(h+1))/2 - i <= g)
        ans = ans+dp[i];
        ans %= m;
    }
    cout<<ans<<"\n";

    return 0;
}