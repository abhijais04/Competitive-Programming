#include <bits/stdc++.h>
using namespace std;
long long a[110][110][2];
int main()
{
    long long i,j,k,n;
    //scanf("%lld",&t);
    while(scanf("%lld",&n)!=EOF)
    {
       // long long int n;
        //scanf("%lld",&n);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                a[i][j][0]=a[i][j][1]=0;
            }
        }
        for(i=1;i<=n;i++)
        {
            long long z;
            scanf("%lld",&z);
            a[i][i][1]=a[i][i][0]=z;
        }
        for(j=1;j<=n;j++)
        {
         //    cout<<" j  n :"<<j<<" "<<n<<"\n";
            for(i=j;i>0;i--)
            {
                if(j>i)
                {
                   if(j==i+1)
                   {
                       a[i][j][1]=a[i][j-1][0]*a[i+1][j][0];
                       a[i][j][0]=(a[i][j-1][0]+a[i+1][j][0])%100;
                   }
                   else
                   {
                       long long m=1000000000,tmp,tk;
                       for(k=i;k<j;k++)
                       {
                           if(i==k)
                            tmp=a[k+1][j][1]+(a[i][k][0]*a[k+1][j][0]);
                           else if(k==j-1)
                            tmp=a[i][k][1]+(a[i][k][0]*a[k+1][j][0]);
                            else
                           tmp=a[i][k][1]+a[k+1][j][1]+(a[i][k][0]*a[k+1][j][0]);
                           if(tmp<m)
                           {
                               m=tmp;
                               tk=k;
                           }
                       }
                       a[i][j][1]=m;
                       a[i][j][0]=(a[i][tk][0]+a[tk+1][j][0])%100;
                   }
                }//cout<<;
            }
        }
     /*   for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
                cout<<a[i][j][1]<<" ";
            cout<<endl;
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
                cout<<a[i][j][0]<<" ";
            cout<<endl;
        }*/
        if(n==1)
            a[1][1][1]=0;
        printf("%lld\n",a[1][n][1]);
    }
    return 0;
}
