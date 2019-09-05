#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int main()
{
    int ans=0;
    int a[3];
    int n;
    cin>>n;
    cin>>a[0]>>a[1]>>a[2];
    for(int i=0;i<=n/a[0];i++)
    {
        int lft=n-i*a[0];
        for(int j=0;j<=lft/a[1];j++)
        {
            if((lft-j*a[1])%a[2]==0)
            {
                ans=max(ans,i+j+(lft-j*a[1])/a[2]);
            }
        }
    }
    cout<<ans<<"\n";
}