#include <bits/stdc++.h>
using namespace std;
//long long m[2][2];
long long mod=1000000000+7;
void multiply(long long F[2][2], long long M[2][2])
{
  long long x =  ((F[0][0]*M[0][0])%mod + (F[0][1]*M[1][0])%mod)%mod;
  long long y =  ((F[0][0]*M[0][1])%mod + (F[0][1]*M[1][1])%mod)%mod;
  long long z =  ((F[1][0]*M[0][0])%mod + (F[1][1]*M[1][0])%mod)%mod;
  long long w =  ((F[1][0]*M[0][1])%mod + (F[1][1]*M[1][1])%mod)%mod;

  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}
long long fibb(long long n)
{
    long long a[2][2]={{1,0},{0,1}},i,j,k;
     long long m[2][2]={{1,1},{1,0}};
    while(n>0)
    {
        if(n%2==1)
        {
            multiply(a,m);

        }
        multiply(m,m);
        n=n/2;
    }
    return a[0][1];
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long n,m;
        scanf("%lld%lld",&n,&m);
       // long long i=0,j=1;
       long long t1=fibb(n+1);
       t1--;
       //cout<<t1<<"\n";
       long long t2=fibb(m+2);
       t2--;
       //cout<<t2<<"\n";
       t2=(t2-t1)%mod;
       if(t2<0)
        t2+=mod;
        printf("%lld\n",t2);

    }
    return 0;
}
