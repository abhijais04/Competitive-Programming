#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    while(1)
    {
        int n,k;
        cin>>n>>k;
        if(n==0||k==0)
            break;
        int i=0,r=0;
        for(i=2;i<=n;i++)
        {
            r=(r+k)%i;
        }
        cout<<n<<" "<<k<<" "<<r+1<<"\n";
    }
    return 0;
}
