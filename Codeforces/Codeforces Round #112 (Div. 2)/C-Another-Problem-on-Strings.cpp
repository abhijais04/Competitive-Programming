#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
ll pre[1000010];
ll next[1000010];

ll compute(string str)
{
    ll ans=0,l=0,r=0;
    ll len=str.length();
    while(str[l]=='1') l++;
    if(l==len) {return 0;}
    r=l;
    while(r<len&&str[r]=='0') r++;
    r--;
    while(l<len&&r<len)
    {
        ll tmp = (r-l+1);
        ans+=(tmp*(tmp+1))/2;
        l=r+2;
        while(l<len&&str[l]=='1') l++;
        if(l<len)
            {
                r=next[l];
                r--;
            }
    }
    return ans;

}
int main()
{
    int k;
    cin>>k;
    string str;
    cin>>str;
    int len=str.length();

    ll p=-1;
    for(int i=0;i<len;i++)
    {
        pre[i]=p;
        if(str[i]=='1')
            p=i;
    }
    p = len;
    for(int i=len-1;i>=0;i--)
    {
        next[i]=p;
        if(str[i]=='1')
            p=i;
    }
    if(k==0)
    {
        cout<<compute(str)<<"\n";
        return 0;
    }
    ll l=0,r=-1;
    ll cnt=0;
    while(r<len&&cnt<k)
    {
        r++;
        if(str[r]=='1') cnt++;
    }
    if(cnt<k) {cout<<"0\n"; return 0;}
    while(str[l]=='0') l++;
    ll ans=0;
    while(r<len)
    {
            ans+=(l-pre[l])*(next[r]-r);
            l=next[l];
            r=next[r];
    }
    cout<<ans<<"\n";
    return 0;
}