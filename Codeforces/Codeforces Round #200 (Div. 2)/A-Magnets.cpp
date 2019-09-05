#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int ans=0;
    cin>>n;
    int tmp;
    cin>>tmp;
    int pre=tmp%2;
    ans++;
    for(int i=1;i<n;i++)
    {
        int cur;
        cin>>cur;
        int cc = cur/10;
        cur%=2;
        if(pre==cc)
            ans++;
        pre=cur;
    }
    cout<<ans<<"\n";
}