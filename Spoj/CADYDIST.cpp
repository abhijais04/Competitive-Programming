#include <bits/stdc++.h>
using namespace std;
int main()
{
    while(1)
    {
        long long n,i;
        cin>>n;
        if(n==0)
            break;
        long long a[n],p[n],sum=0;
        for(i=0;i<n;i++)
        cin>>a[i];
        for(i=0;i<n;i++)
            cin>>p[i];
        sort(a,a+n);
        sort(p,p+n);
        for(i=0;i<n;i++)
        {
            sum+=(a[i]*p[n-1-i]);
        }
        cout<<sum<<"\n";
    }
    return 0;
}
