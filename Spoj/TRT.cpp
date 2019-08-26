#include <bits/stdc++.h>
using namespace std;
int n;
int a[2000];
int dp[2000][2000]={0};
int val(int beg,int end)
{
    if(beg>end)
    return 0;
    if(dp[beg][end]!=0)
    return dp[beg][end];
    int tmp=n-(end-beg+1)+1;
    dp[beg][end]=max(val(beg+1,end)+a[beg]*tmp,val(beg,end-1)+a[end]*tmp);
    return dp[beg][end];
}
int main() {
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("%d",val(0,n-1));
	return 0;
}
