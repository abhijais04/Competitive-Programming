#include<bits/stdc++.h>
using namespace std;
long long mod=10000007;
long long me(long long a,long long b,long long m)
{
    long long ans=1;
    while(b)
    {
        if(b&1)
        {
            ans=(ans%m*a%m)%m;
        }
        a=(a%m*a%m)%m;
        b=b/2;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(1)
    {
        long long n,k,a,b,c,d;
        cin>>n>>k;
        if(n==0&&k==0)
            break;
        a=me(n,k,mod);
        b=me(n,n,mod);
        c=me(n-1,k,mod);
        c=(2*c)%mod;
        d=me(n-1,n-1,mod);
        d=(2*d)%mod;
        a=(a%mod+b%mod)%mod;
        c=(c%mod+d%mod)%mod;
        a=(a%mod+c%mod)%mod;
        cout<<a<<"\n";
    }
    return 0;
}
