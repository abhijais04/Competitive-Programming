#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
struct node
{
    int a,b;
    bool operator<(const node n1) const
    {
        if(this->a!=n1.a)
        {
            return this->a < n1.a;
        }
        return this->b < n1.b;
    }
};
int main()
{
    int n,m;
    cin>>n;
    vector<node> v;
    for(int i=0;i<n;i++)
    {
        node tmp;
        cin>>tmp.a>>tmp.b;
        v.pb(tmp);
    }
    sort(v.begin(),v.end());
    int d=0;
   // int mx=0;
    for(int i=0;i<n;i++)
    {
        int tmp = min(v[i].a,v[i].b);
        if(tmp>=d)
            d=tmp;
        else
            d=max(v[i].a,v[i].b);
    }
    cout<<d<<"\n";
    return 0;
}