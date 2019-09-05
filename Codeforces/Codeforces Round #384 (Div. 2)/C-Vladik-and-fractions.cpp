#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
string str;
int main()
{
    ll n;
    cin>>n;
    if(n<2)
        cout<<"-1\n";
    else
    {
        ll s=n+1;
        ll t =n*s;
        cout<<n<<" "<<s<<" "<<t<<"\n";
    }
    return 0;
}