#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
ll el[1000100];
ll sum[1001000];
int main()
{
    int q;
    scanf("%d",&q);
    ll csum=0,n=1;
    while(q--)
    {
        int t;
        scanf("%d",&t);
        if(t==1)
        {
            int x,a;
            scanf("%d%d",&x,&a);
            csum+=(x*a);
            sum[x]+=a;
        }
        else if(t==2)
        {
            int x;
            scanf("%d",&x);
            n++;
            el[n]=x;
            csum+=x;
        }
        else
        {
            csum-=el[n];
            el[n]=0;
            csum-=sum[n];
            n--;
            sum[n]+=sum[n+1];
            sum[n+1]=0;
        }
        double res = (double)csum/n;
        printf("%.8lf\n",res);
    }
    return 0;
}