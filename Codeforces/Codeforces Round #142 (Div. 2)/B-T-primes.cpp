#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int nn=1000010;
bool p[1000100];
void sieve()
{
    for(int i=2;i*i<nn;i++)
    {
        if(p[i]==false)
        {
            for(int j=2*i;j<nn;j+=i)
            {
                p[j]=true;
            }
        }
    }
}
int main()
{
    sieve();
    ll n;
    cin>>n;
   // ll a[n];
    for(int i=0;i<n;i++)
    {
        ll tmp;
        cin>>tmp;
        ll ss=sqrt(tmp);
        if(tmp>1&&ss*ss==tmp&&(p[ss]==false))
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
    }
    return 0;
}