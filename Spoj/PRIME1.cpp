#include<bits/stdc++.h>
using namespace std;
int p[100001];
bool a[100001]={false};
int n=100000;
int z=0;
void sieve()
{
    int i,j;
    for(i=2;i<=n;i++)
    {
        if(a[i]==false)
        {
            p[z++]=i;
            for(j=2;j*i<=n;j++)
            {
                a[j*i]=true;
            }
        }
    }
}
int main()
{
    int t;
    sieve();
    scanf("%d",&t);
    while(t--)
    {
        bool a2[100001]={false};
        int n,m,s=0,i,j,c;
        scanf("%d%d",&m,&n);
        for(int x=0;p[x]<=n&&x<z;x++)
        {

            if(m<=p[x])
                c=p[x]+p[x];
            else
            {
                c=(m/p[x]);
                c=c*p[x];
            }
                for(i=c-m;i<n-m+1;i=i+p[x])
                {
                        if(i>=0)
                        a2[i]=true;

                }
        }
        for(i=0;i<n-m+1;i++)
        {

            if(a2[i]==false)
            {
                if(i+m!=1)
                cout<<i+m<<"\n";
            }
        }
    }
    return 0;
}