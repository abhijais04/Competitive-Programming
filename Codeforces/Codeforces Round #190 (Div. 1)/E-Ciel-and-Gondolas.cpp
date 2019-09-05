#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sc(x) scanf("%d",&x)
int dp[802][4002];
int ff[4002][4002];
int mx=1e9;
int n;
int cost(int i,int j)
{
    int res = ff[j][j] + ff[i-1][i-1] - ff[i-1][j] - ff[j][i-1];
    return res>>1;
}
void compute(int k,int l,int r,int optl,int optr)
{
    if(r<l)
        return;
    int m = (l+r)/2;
    int idx = -1;
    dp[k][m] = mx;
    for(int j=optl;j<=min(optr,m);j++)
    {
        int tmp = dp[k-1][j-1] + cost(j,m);
        if(tmp<=dp[k][m])
        {
            dp[k][m]=tmp;
            idx = j;
        }
    }
    compute(k,l,m-1,optl,idx);
    compute(k,m+1,r,idx,optr);
}
int main()
{
    int k;
    sc(n); sc(k);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            char c = '%';
            while(!isdigit(c))
                c = getchar();
            ff[i][j] = c-'0';
            ff[i][j]+=ff[i-1][j]+ff[i][j-1]-ff[i-1][j-1];
        }
    for(int i=1;i<=n;i++)
        dp[1][i] = cost(1,i);
    for(int i=2;i<=k;i++)
        compute(i,1,n,1,n);
    printf("%d\n",dp[k][n]);
    return 0;
}