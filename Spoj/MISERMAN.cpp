#include <bits/stdc++.h>
using namespace std;
int min2(int a,int b,int c)
{
    if(a<=b&&a<=c)
        return a;
    if(b<=a&&b<=c)
        return b;
    else
        return c;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int a[n][m],i,j;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        scanf("%d",&a[i][j]);
    for(i=n-2;i>=0;i--)
    {
        for(j=0;j<m;j++)
        {
            if(j==0)
            {
                if(m>1)
                    a[i][j]+=min(a[i+1][j],a[i+1][j+1]);
                else
                    a[i][j]+=a[i+1][j];
            }
            else if(j==m-1)
            {
                if(m>1)
                    a[i][j]+=min(a[i+1][j],a[i+1][j-1]);
                else
                    a[i][j]+=a[i+1][j];
            }
            else
                a[i][j]+=min2(a[i+1][j],a[i+1][j-1],a[i+1][j+1]);
        }
    }
    int mn=a[0][0];
    for(i=0;i<m;i++)
        if(a[0][i]<mn)
        mn=a[0][i];
    printf("%d\n",mn);
    return 0;
}
