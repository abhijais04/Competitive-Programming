#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int nn=1000010;

int main()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    int ans=0,sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(i<k)
            sum+=a[i];
    }
    ans=sum;
    int idx=0;
    for(int i=1;i<=n-k;i++)
    {
        sum=sum-a[i-1]+a[k+i-1];
        if(sum<ans)
        {
            ans=min(ans,sum);
            idx=i;
        }
    }
    cout<<idx+1<<"\n";
    return 0;
}