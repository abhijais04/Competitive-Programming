#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int z;
    for(z=1;z<=t;z++)
    {
        long long n,i;
        cin>>n;
        long long a[n],ans=0,sum=0;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            sum+=a[i];
            ans=min(sum,ans);
        }
        ans--;
        ans=-ans;
        ans=max((long long)1,ans);
        cout<<"Scenario #"<<z<<": ";
        cout<<ans<<"\n";
    }

}
