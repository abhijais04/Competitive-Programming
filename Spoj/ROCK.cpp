#include<bits/stdc++.h>
using namespace std;
#define ll long long
int l,dp[210][210],c[210][210];
char str[210];
int getval(int s,int e)
{
    if(s>e)
        return 0;
    if(c[s][e]>(e-s+1)-c[s][e])
        return (e-s+1);
    if(dp[s][e]!=-1)
        return dp[s][e];
    int ans=0;
    for(int i=s;i<e;i++)
    {
        ans= max(ans,getval(s,i)+getval(i+1,e));
    }
    return dp[s][e]=ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int i,j,k;
        cin>>l;
        scanf("%s",&str);
        //int i;
        for(i=0;i<=l;i++)
        {
            for(j=0;j<=l;j++)
            {
                c[i][j]=0;
                    dp[i][j]=-1;
            }
        }
        for(i=0;i<l;i++)
        {
            int cnt=0;
            for(j=i;j<l;j++)
            {
                if(str[j]=='1')
                    cnt++;
                c[i][j]=cnt;
            }
        }
        /*for(i=0;i<l;i++)
        {
            for(j=0;j<l;j++)
            {
                cout<<c[i][j]<<" ";
            }
            cout<<"\n";
        }*/
        printf("%d\n",getval(0,l-1));
    }
    return 0;
}
