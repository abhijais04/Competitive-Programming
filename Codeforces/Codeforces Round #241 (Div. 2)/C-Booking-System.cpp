#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sc(x) scanf("%d",&x)
using namespace std;
struct node
{
    int p,s,id;
    node() {};
    node(int _p,int _s,int _id)
    {
        p = _p; s = _s; id = _id;
    }
    bool operator<(node n1)const
    {
        return this->p < n1.p;
    }
};
struct sz
{
    int s;
    int id;
    sz() {}
    sz(int _s,int _id) { s = _s; id = _id;}
    bool operator<(sz n1)const
    {
        return this->s < n1.s;
    }
};
vector<node> v;
vector<sz> v2;
bool booked[1010];
int ss[1010];
int idd[1010];
int main()
{
    int n;
    sc(n);
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        v.pb(node(b,a,i+1));
    }
    sort(v.begin(),v.end());
    int k;
    cin>>k;
    for(int i=0;i<k;i++)
    {
        int a;
        sc(a);
        v2.pb(sz(a,i+1));
    }
    sort(v2.begin(),v2.end());
    for(int i=0;i<k;i++)
    {
        ss[i] = v2[i].s; idd[i] = v2[i].id;
    }
    int ans=0;
    int cnt=0;
    vector<pair<int,int> > fans;
    fans.clear();
    for(int i=n-1;i>=0;i--)
    {
        int idx = lower_bound(ss,ss+k,v[i].s) - ss;
        for(idx;idx<k;idx++)
        {
            if(!booked[idx])
            {
                booked[idx]=true;
                ans+=v[i].p;
                cnt++;
                fans.pb({v[i].id,idd[idx]});
                //cout<<v[i].id<<" "<<idd[idx]<<"\n";
                break;
            }
        }
    }
    cout<<cnt<<" "<<ans<<"\n";
    for(int i=0;i<fans.size();i++)
    {
        cout<<fans[i].first<<" "<<fans[i].second<<"\n";
    }


    return 0;

}