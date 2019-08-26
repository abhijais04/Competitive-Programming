#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        ll t1 = n-k;
        ll t2= (k-1)/2;
        if(t1&t2)
            cout<<"0\n";
        else
            cout<<"1\n";
    }
    return 0;
}
