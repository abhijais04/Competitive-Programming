#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int main()
{
    ll n,h,k;
    cin>>n>>h>>k;
    ll a[n],cnt=0;
    for(ll i=0;i<n;i++)
        {
            cin>>a[i];
        }
    int lft=0;
    for(ll i=0;i<n||lft>0;)
    {
        if(lft+a[i]<=h&&i<n)
        {
            lft+=a[i];
            i++;
            //continue;
        }
        else
        {
            if(lft>=k)
            {
                cnt+=(lft/k);
                lft=lft%k;
            }
            else
            {
                cnt++;
                lft=0;
            }
           // cout<<cnt<<"\n";
        }
        //cout<<lft<<" "<<i<<"\n";
    }
        cout<<cnt<<"\n";
    return 0;
}