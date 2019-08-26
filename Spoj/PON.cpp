#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define gc getchar
//_unlocked
int read() {
  char c = gc();
  while(c<'0' || c>'9') c = gc();
  int ret = 0;
  while(c>='0' && c<='9') {
    ret = 10 * ret + c - 48;
    c = gc();
  }
  return ret;
}
ll mulme(ll a,ll b,ll c)
{
    ll ans=0;
    a=a%c;
    while(b>0)
    {
        if(b%2==1)
        {
            ans=(ans+a)%c;
        }
        a=(a+a)%c;
        b=b/2;
    }
    return ans%c;
}
ll me(ll a,ll b,ll c)
{
    ll ans=1;
    a=a%c;
    while(b>0)
    {
        if(b%2==1)
        {
            ans=mulme(ans,a,c)%c;
        }
        a = mulme(a,a,c)%c;
        //a=(a*a)%c;
        b=b/2;
    }
    return ans%c;
}

bool isprime(ll n,ll it)
{
    ll p=n,i;
    if(n==2)
        return true;
    if(n<2)
        return false;
    if(n%2==0&&n!=2)
        return false;
    ll s=n-1;
    while(s%2==0)
    {
        s=s/2;
    }
    for(i=0;i<it;i++)
    {
        ll a=(rand()%(p-1))+1;
        ll temp=s;
        ll mod = me(a,temp,p);
        while(temp!=p-1 && mod!=1 && mod!=p-1)
        {
            mod=mulme(mod,mod,p);
            temp *= 2;
        }
        if(mod!=p-1&&temp%2==0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n,it=5;
        cin>>n;
        if(isprime(n,it)==true)
        {
            cout<<"YES\n";
        }
        else
            cout<<"NO\n";
    }
    return 0;
}
