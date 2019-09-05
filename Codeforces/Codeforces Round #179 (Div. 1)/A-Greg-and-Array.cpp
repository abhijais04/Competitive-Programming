#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
ll q[100010];
ll a[100010];
ll c[100010];
ll st[100010];
ll ed[100010];
ll qq[100010];
int main()
{
    ll n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<m;i++)
    {
        ll tmp;
        int l,r;
        cin>>l>>r;
        cin>>tmp;
        l--;
        r--;
        st[i]=l;
        ed[i]=r;
        q[i]=tmp;
    }
    while(k--)
    {
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        c[x]++;
        c[y+1]--;
    }
    ll tmp=0;
    for(int i=0;i<m;i++)
    {

        tmp+=c[i];
        //cout<<tmp<<" ";
        qq[st[i]]+=tmp*q[i];
        qq[ed[i]+1]-=tmp*q[i];
    }
   // cout<<"\n";
    tmp=0;
    for(int i=0;i<n;i++)
    {
        tmp+=qq[i];
        cout<<a[i]+tmp<<" ";
    }
    cout<<"\n";
}