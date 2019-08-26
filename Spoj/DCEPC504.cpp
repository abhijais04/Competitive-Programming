#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll ans=0,i;
        ll n,k;
        cin>>n>>k;
        ll k1=k;
        int par = 0;
        for(i=n;i>1;i--)
        {
            if(ans==0)
            {
                if(k%2==1)
                {
                    par=0;
                }
                else
                    par=1;
            }
            else
            {
                if(k%2==1)
                    par=1;
                else
                    par=0;
            }
            if(k%2==1)
            {
                k=k/2 ;
                k++;
            }
            else
                k=k/2;
            ans=par;
        }
        if(par==1)
            cout<<"Female\n";
        else
            cout<<"Male\n";
    }
    return 0;
}
