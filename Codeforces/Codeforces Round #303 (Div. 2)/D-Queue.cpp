#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int main()
{
    int n,m;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int tmp;
        cin>>tmp;
        v.pb(tmp);
    }
    sort(v.begin(),v.end());
    int ans=0;
    int d=0;
   // int mx=0;
    for(int i=0;i<v.size();)
    {
        if(d<=v[i])
        {
            d+=v[i];
            i++;
        }
        else
        {
            i++;
            ans++;
        }
    }
    cout<<n-ans<<"\n";
    return 0;
}