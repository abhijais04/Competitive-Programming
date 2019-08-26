#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll p[10010],k[10010];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n,i;
        cin>>n;
        for(i=0;i<n;i++)
            cin>>p[i];
        for(i=0;i<n;i++)
            cin>>k[i];
        ll ans=0;
        for(i=0;i<n;i++)
        {
            if(p[i]>k[i])
                ans^=(p[i]%(k[i]+1));
            else
                ans^=p[i];
        }
        if(ans==0)
        {
            cout<<"Mishra\n";
        }
        else
            cout<<"Amit\n";
    }
    return 0;
}

