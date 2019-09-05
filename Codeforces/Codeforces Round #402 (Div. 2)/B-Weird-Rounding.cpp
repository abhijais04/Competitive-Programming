#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int ca[6],cb[6];
int main()
{
    int k;
    string str;
    cin>>str;
    cin>>k;
    int l=str.length();
    int cnt=0;
    int ans=0;
    for(int i=l-1;i>=0;i--)
    {
        if(cnt==k)
            break;
        if(str[i]=='0')
            cnt++;
        else
            ans++;
    }
    if(cnt!=k)
        ans=l-1;
    cout<<ans<<"\n";
    return 0;
}