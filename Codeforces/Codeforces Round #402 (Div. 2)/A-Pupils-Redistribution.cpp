#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int ca[6],cb[6];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        ca[x]++;
    }
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        cb[x]++;
    }
    int ans=0;
    for(int i=1;i<=5;i++)
    {
        if((ca[i]+cb[i])%2==1)
        {
            cout<<"-1\n";
            return 0;
        }
        if(ca[i]<cb[i])
            ans+=cb[i]-ca[i];

    }
    cout<<ans/2<<"\n";
    return 0;
}