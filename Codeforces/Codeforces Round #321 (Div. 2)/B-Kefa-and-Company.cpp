#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
struct node
{
    int m,ff;
    bool operator<(const node n1)const
    {
        if(this->m!=n1.m)
            return this->m < n1.m;
        return this->ff > n1.ff;
    }
};
int main()
{
    int n,d;
    cin>>n>>d;
    vector<node> v;
    for(int i=0;i<n;i++)
    {
        node tmp;
        cin>>tmp.m>>tmp.ff;
        v.pb(tmp);
    }
    sort(v.begin(),v.end());
    ll mx=0;
    ll l=0,h=0,csum=0;
    while(l<=h&&l<n&&h<n)
    {
        if(v[h].m-v[l].m<d)
        {
            csum+=v[h].ff;
            h++;
            mx=max(mx,csum);
        }
        else
        {
            csum-=v[l].ff;
            mx=max(mx,csum);
            l++;
        }
    }
    cout<<mx<<"\n";
    return 0;
}