#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,i,j,k;
    cin>>n;
    int flag=0;
    for(i=0;i*1234567<=n;i++)
    {
        for(j=0;j*123456<=n-i*1234567;j++)
        {

                if((n-i*1234567-j*123456)%1234==0&&(n-i*1234567-j*123456)>=0)
                {
                    flag=1;
                    break;
                }
            if(flag==1)
                break;
        }
        if(flag==1)
                break;
    }
    if(flag==1)
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}