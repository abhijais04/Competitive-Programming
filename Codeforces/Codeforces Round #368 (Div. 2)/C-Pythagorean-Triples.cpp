#include<bits/stdc++.h>
using namespace std;
#define ll long long
int dp[11010];
int md = 100000023;
int main()
{
    dp[0]=1;
    for(int i=1;i<10101;i++)
        dp[i]=(dp[i-1]*2)%md;
    ll n;
    cin>>n;
    if(n<=2){
        cout<<"-1\n";
        return 0;
    }
    else if(n%2==1){
        ll arya=(n*n+1)/2;
        ll k=n*n-arya;
        cout<<arya<<" "<<k<<"\n";
        return 0;
    }
    else{
        ll raven=n/2;
        ll masasa=(raven*raven)+1;
        ll k=(n*raven)-masasa;
        cout<<masasa<<" "<<k<<"\n";
        return 0;
    }
    return 0;
}