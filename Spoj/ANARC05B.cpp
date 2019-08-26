#include <bits/stdc++.h>
using namespace std;
long long a[2][10100];
int n[2];
long long dp[2][20011];
int bs(int v,int j)
{
    int beg=0;
    int last=n[j];
    int middle=(beg+last)/2;
    while(beg<=last)
    {
        if(v>a[j][middle])
            beg=middle+1;
        else if(v<a[j][middle])
            last=middle-1;
        else if(v==a[j][middle])
            return middle;
        middle=(beg+last)/2;
    }
    return -1;
}
long long val(int i,int j)
{
    if(i>=n[j])
    return 0;
    if(dp[j][i]!=0)
        return dp[j][i];
    int j2;
    if(j==1)
    j2=0;
    else if(j==0)
    j2=1;
    int tmp=bs(a[j][i],j2);
    if(tmp!=-1)
    {
        dp[j][i]=a[j][i]+max(val(i+1,j),val(tmp+1,j2));
    }
    else
        dp[j][i]=a[j][i]+val(i+1,j);
    return dp[j][i];
}
int main()
{
    while(1)
    {
        int i;
        for(i=0;i<20000;i++)
        dp[1][i]=dp[0][i]=0;
        scanf("%d",&n[0]);
        if(n[0]==0)
            break;
        for(i=0;i<n[0];i++)
        {
            scanf("%lld",&a[0][i]);
        }
        scanf("%d",&n[1]);
        for(i=0;i<n[1];i++)
            {
                scanf("%lld",&a[1][i]);
            }
        long long ans1=val(0,0);
        for(i=0;i<20000;i++)
        dp[0][i]=dp[1][i]=0;;
        long long ans=val(0,1);
        printf("%lld\n",max(ans1,ans));
    }
    return 0;
}
