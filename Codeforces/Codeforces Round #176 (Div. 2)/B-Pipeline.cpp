#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

int check(ll n,ll k,ll mx)
{
    ll low = (k*(k+1))/2;
    ll high = (mx*(mx+1))/2;
    ll kk=mx-k;
    high-=(kk*(kk+1))/2;
    if(n>=low&&n<=high)
        return 1;
    if(low>=n)
        return 1;
    if(high<=n)
        return -1;

}
int main()
{
    //while(1){
    ll n,k;
    cin>>n>>k;
    ll need = n-1;
    ll l=1;
    ll h=k-1;
    if(n==1)
    {
        cout<<"0\n";
        //continue;
        return 0;
    }
    while(l<=h)
    {
        ll mid = (l+h)/2;
        if(check(n-1,mid,k-1)==1)
        {
            h=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    if(l>=k)
        cout<<"-1\n";
    else
        cout<<l<<"\n";
   // }
}