#include <bits/stdc++.h>
using namespace std;
int a[1000010],max_final[1000010],min_final[1000010],ml[1000010],mr[1000010];
int main()
{
    int n;
    scanf("%d",&n);
    int i,k,c;
    scanf("%d",&k);
    scanf("%d",&c);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    mr[n-1]=a[n-1];
    ml[0]=a[0];
    for(i=1;i<n;i++)
    {
         ml[i] = (i%k==0) ? a[i]: max(a[i],ml[i-1]);
         int j = n-i-1;
         mr[j] = (j%k==0) ? a[j] :max(a[j],mr[j+1]);
    }
    for(i=0;i<n-k+1;i++)
    {
        max_final[i] =max(mr[i],ml[i+k-1]);
    }
    mr[n-1]=a[n-1];
    ml[0]=a[0];
    for(i=1;i<n;i++)
    {
         ml[i] = (i%k==0) ? a[i]: min(a[i],ml[i-1]);
         int j = n-i-1;
         mr[j] = (j%k==0) ? a[j] :min(a[j],mr[j+1]);
    }
    for(i=0;i<n-k+1;i++)
    {
        min_final[i] =min(mr[i],ml[i+k-1]);
    }
    int flag=0;
    for(i=0;i<n-k+1;i++)
    {
        if(max_final[i]-min_final[i]<=c)
            {
                cout<<i+1<<"\n";
                flag++;
            }
    }
    if(flag==0)
        cout<<"NONE";
    printf("\n");
    return 0;
}
