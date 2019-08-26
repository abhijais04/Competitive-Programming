#include <bits/stdc++.h>
using namespace std;
char ch[7000];
int dp[6110][6110];
int val(int i,int j)
{
    if(i>=j)
    return 0;
   if(dp[i][j]!=0)
    return dp[i][j];
    if(ch[i]!=ch[j])
    {
        dp[i][j]=min(1+val(i,j-1),1+val(i+1,j));
        //return 
        return dp[i][j];
    }
    else if(ch[i]==ch[j])
    {
        dp[i][j]=val(i+1,j-1);
       return dp[i][j];
    }
}
int main() {
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    int i,j;
	  scanf("%s",&ch);
	int l=strlen(ch);
	   for(i=0;i<l;i++)
	   {
	       for(j=0;j<l;j++)
	       dp[i][j]=0;
	   }
	   int ans=val(0,l-1);
	printf("%d\n",ans);
	}
	
	return 0;
}
