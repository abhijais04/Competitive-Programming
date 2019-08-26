#include <bits/stdc++.h>
using namespace std;
int mx(int a,int b)
{
    if(a>b)
    return a;
    else
    return b;
}
int mx2(int a,int b,int c)
{
    if(a>=b&&a>=c)
    return a;
    else if(b>=a&&b>=c)
    return b;
    else
    return c;
}

int main() {
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    int n,m;
	    scanf("%d%d",&n,&m);
	    int i,j,a[n][m];
	    for(i=0;i<n;i++)
	    {
	        for(j=0;j<m;j++)
	        scanf("%d",&a[i][j]);
	    }
	    for(i=n-1;i>0;i--)
	    {
	        for(j=0;j<m;j++)
	        {
	            if(j==0)
	            {
	                if(m>1)
	                a[i-1][j]+=mx(a[i][j],a[i][j+1]);
	                else
	                a[i-1][j]+=a[i][j];
	            }
	            else if(j==m-1)
	            {
	                if(m>1)
	                a[i-1][j]+=mx(a[i][j],a[i][j-1]);
	                else
	                a[i-1][j]+=a[i][j];
	            }
	            else if(j>0&&j<m-1)
	            a[i-1][j]+=mx2(a[i][j],a[i][j+1],a[i][j-1]);
	        }
	    }
	    int ans=a[0][0];
	    for(i=0;i<m;i++)
	    {
	        if(a[0][i]>ans)
	        ans=a[0][i];
	    }
	    printf("%d\n",ans);
	}
	return 0;
}
