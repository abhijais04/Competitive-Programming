#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int main()
{
    ll n,k;
    cin>>n>>k;
    if(k%2==1)
        cout<<"1\n";
    else
    {
        int ans=n;
        ll l=1,h=1;
        for(int i=0;i<n;i++)
            h=h*2;
        h--;
        while(l<=h)
        {
            ll mid = (l+h)/2;
            if(mid==k)
                break;
            if(mid<k)
            {
                ans--;
                l=mid+1;
            }
            else
            {
                ans--;
                h=mid-1;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}