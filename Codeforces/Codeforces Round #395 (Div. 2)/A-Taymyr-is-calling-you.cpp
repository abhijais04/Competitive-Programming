#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

int main()
{
    int n,m,z;
    cin>>n>>m>>z;
    int t=__gcd(n,m);
    t=n*m/t;

    cout<<z/t<<"\n";
    return 0;
}