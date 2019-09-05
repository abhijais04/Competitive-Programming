#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int main()
{
    int ans=0;
    int n;
    cin>>n;
    int tmp;
    cin>>tmp;
    if(tmp%2==0)
    {
        ans=1;
    }
    else
        ans=2;
    cout<<ans<<"\n";
    for(int i=0;i<n-1;i++)
    {
        cin>>tmp;
        if(tmp%2==0)
        {
            if(ans==2)
                ans=1;
            else
                ans=2;
        }
        cout<<ans<<"\n";
    }
    return 0;

}