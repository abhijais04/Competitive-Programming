#include<iostream>
using namespace std;
#define ll long long
#define pb push_back
int main()
{
    ll l,r;
    cin>>l>>r;
    ll ans=0;
    for(int i=62;i>=0;i--)
    {
        if(((1LL<<i)&l) != ((1LL<<i)&r))
        {
            ans = (1LL<<(i+1)) - 1;
            break;
        }
    }
    cout<<ans<<"\n";
}