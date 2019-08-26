#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int a[n],i,k;
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    scanf("%d",&k);
    int max_final[n-k+1];
    int ml[n],mr[n];
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
        cout<<max_final[i]<<" ";
    }
    printf("\n");
    return 0;
}
