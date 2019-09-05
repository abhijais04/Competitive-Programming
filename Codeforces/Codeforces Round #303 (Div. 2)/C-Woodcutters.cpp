#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
struct node
{
    int x,h;
    bool operator<(const node n1)const
    {
        return this->x < n1.x;
    }
};
int n;
vector<node> v;
int rigt[100010];
int ch_left(int i)
{
    if(i==0)
        return true;
    if(rigt[i-1]==1)
    {
        if(v[i].x-v[i-1].x-1-v[i-1].h>=v[i].h)
            return true;
            return false;
    }
    return (v[i].x-v[i-1].x>v[i].h);
}
int ch_right(int i)
{
    if(i==n-1)
        return true;
    if(v[i+1].x-v[i].x>v[i].h)
        return true;
    return false;
}
int main()
{
   // int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        node tmp;
        cin>>tmp.x>>tmp.h;
        v.pb(tmp);
    }
    sort(v.begin(),v.end());
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(ch_left(i))
        {
            ans++;
        }
        else if(ch_right(i))
        {
            ans++;
            rigt[i]=1;
        }
    }
    cout<<ans<<"\n";
    return 0;
}