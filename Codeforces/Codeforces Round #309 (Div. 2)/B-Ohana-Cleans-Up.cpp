#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
map<string,int> mp;
int main()
{
    int n;
    cin>>n;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        string tmp;
        cin>>tmp;
        mp[tmp]++;
        ans=max(mp[tmp],ans);
    }
    cout<<ans<<"\n";
    return 0;
}