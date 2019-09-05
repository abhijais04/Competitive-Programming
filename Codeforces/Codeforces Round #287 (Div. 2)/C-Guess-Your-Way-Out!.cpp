#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll h,n;
    cin>>h>>n;
    ll pow[55],i;
    pow[0]=1;
    for(i=1;i<54;i++)
        pow[i]=pow[i-1]*(ll)2;
    ll ans=0;
    n = n+pow[h]-1;
    for(i=h;i>0;i--)
    {
        if(n%2==0)
        {
            if((n/2)%2==0)
            {
                ans+=pow[h-i+1];

            }
            else
                ans++;
        }
        else
        {
            if((n/2)%2==1)
            {
                ans+=pow[h-i+1];
            }
            else
                ans++;
        }
        n=n/2;
    }
    cout<<ans<<"\n";

}