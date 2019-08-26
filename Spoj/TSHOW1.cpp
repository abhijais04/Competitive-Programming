#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t;
    cin>>t;
    ll pt[63];
    pt[0]=1;
    for(int it=1;it<63;it++)
        pt[it]=pt[it-1]*(ll)2;
    while(t--)
    {
        ll k,i;
        cin>>k;
        ll tmp=2,pre=0,dg=1,sum=2;
        while(sum<k)
        {
            tmp*=2;
            sum+=tmp;
            dg++;
        }
        //cout<<dg<<"\n";
        ll pos=k-(sum-tmp);
        if(pos==0)
        {
            pos=tmp;
           // dg--;
        }
        //cout<<pos<<" \n";
        int a[dg];
        for(i=0;i<dg;i++)
        {
            //cout<<i<<" ";

            ll d=pos/pt[dg-i-1],r=pos%pt[dg-i-1];
            //cout<<d<<" "<<r<<"\n";
            if(r==0)
            {
                if(d%2==1)
                {
                    a[i]=5;
                }
                else
                    a[i]=6;
            }
            else
            {
                if(d%2==1)
                    a[i]=6;
                else
                    a[i]=5;
            }
          //  tmp/=2;
        }
        for(i=0;i<dg;i++)
            cout<<a[i];
        cout<<"\n";
    }
}
