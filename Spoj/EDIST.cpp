#include<bits/stdc++.h>
using namespace std;
char ch1[2010],ch2[2010];
int dp[2010][2010];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int i,j;
        scanf("%s",&ch1);
        scanf("%s",&ch2);
        int l1=strlen(ch1),l2=strlen(ch2);
        for(i=0;i<=l1;i++)
        {
            for(j=0;j<=l2;j++)
            {
                if(i==0)
                {
                    dp[i][j]=j;
                }
                else if(j==0)
                {
                    dp[i][j]=i;
                }
                else
                    dp[i][j]=0;
            }
        }
        for(i=1;i<=l1;i++)
        {
            for(j=1;j<=l2;j++)
            {
                int tmp=1;
                if(ch1[i-1]==ch2[j-1])
                    tmp=0;
                tmp=tmp+dp[i-1][j-1];
                int tmp2=min(1+dp[i-1][j],1+dp[i][j-1]);
                dp[i][j]=min(tmp,tmp2);
            }
        }
        cout<<dp[l1][l2]<<"\n";
    }
    return 0;
}