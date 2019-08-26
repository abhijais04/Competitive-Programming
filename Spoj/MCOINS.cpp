#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,m,mx=0,i;
    scanf("%d%d%d",&n,&k,&m);
    int ar[m];
    for(i=0;i<m;i++)
    {
        scanf("%d",&ar[i]);
        if(ar[i]>mx)
            mx=ar[i];
    }
    bool a[mx+1];
    for(i=0;i<=mx;i++)
        a[i]=false;
    a[1]=true;
    //a[n]=true;
    //a[k]=true;
    for(i=2;i<=mx;i++)
    {
        if(i>=n&&i>=k)
        {
            if(a[i-k]==true&&a[i-n]==true&&a[i-1]==true)
                a[i]=false;
            else
                a[i]=true;
        }
        else if(i>=k&&i<n)
        {
            if(a[i-k]&&a[i-1])
                a[i]=false;
            else
                a[i]=true;
        }
        else if(i>=n&&i<k)
        {
            if(a[i-1]&&a[i-n])
                a[i]=false;
            else
                a[i]=true;
        }
        else
        {
            if(a[i-1])
                a[i]=false;
            else
                a[i]=true;
        }
    }
    for(i=0;i<m;i++)
    {
        if(a[ar[i]]==true)
            printf("A");
        else
            printf("B");
    }
    printf("\n");
    return 0;
}
