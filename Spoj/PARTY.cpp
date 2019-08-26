#include<bits/stdc++.h>
using namespace std;

int main()
{
    while(1)
   { 
       
       int m,n;
    scanf("%d%d",&m,&n);
    if(n==0&&m==0)
    break;
    int ar[n+1][m+1];
    int cost[n+1],fn[n+1],i,j,t=0;
    cost[0]=0;
    fn[0]=0;
    for(i=0;i<=n;i++)
    {
    	for(j=0;j<=m;j++)
           ar[i][j]=0;
    	
    }
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&cost[i],&fn[i]);
    }
    for(i=1;i<=m;i++)
    {
        if(cost[1]<=i)
        {//if(i==m)
            //+=cost[1];
            ar[1][i]=fn[1];}
    }
    for(i=2;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
           if(cost[i]<=j)
           {
               
               ar[i][j]=ar[i-1][j];
               ar[i][j]=max((fn[i]+ar[i-1][j-cost[i]]),ar[i-1][j]);
           }
           else
           ar[i][j]=ar[i-1][j];
        }
    }
    j=m;
    while(ar[n][j]==ar[n][j-1]&&j>0)
    {
        j--;
    }
    printf("%d %d \n",j,ar[n][m]);
       scanf("\n");
   }
    return 0;
}