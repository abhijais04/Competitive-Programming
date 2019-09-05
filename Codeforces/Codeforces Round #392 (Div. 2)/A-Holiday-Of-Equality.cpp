#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
int main()
{
    int n;
    cin>>n;
    int a[n];
    int mx=0;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
        mx=max(mx,a[i]);
    }
    int ans=n*mx-sum;
    cout<<ans<<"\n";
    return 0;
}