#include <bits/stdc++.h>
using namespace std;
bool pr[10000003];
int n = 10000003;
vector <long long >v(10000003,0);
void sieve()
{
    long long i,j;
    for(i=3;i*i<n;i++)
    {
        if(pr[i]==false)
        {
            for(j=i*i;j<n;j+=2*i)
            {
                pr[j]=true;
            }
        }
    }
    for(i=3;i<n;i+=2)
    {
        if(pr[i]==false)
        {
            for(j=i;j<n;j+=2*i)
            {
                if(v[j]==0)
                    v[j]=i;
            }
        }
    }
}
long long fibb[10000003];
int main()
{
    sieve();
    fibb[0]=0;
    fibb[1]=0;
    long long i;
    for(i=2;i<n;i++)
    {
        if(i%2==0)
        {
            fibb[i]=fibb[i-1]+2;
        }
        else
            {
                if(pr[i]==false)
                fibb[i]=fibb[i-1]+i;
                else
                fibb[i]=fibb[i-1]+v[i];
            }
    }
    int t;
    cin>>t;
    while(t--)
    {
        long long  a;
        scanf("%lld",&a);
        printf("%lld\n",fibb[a]);
    }
            return 0;
}
