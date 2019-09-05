#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
struct node
{
    int x,y;
    bool operator<(const node n1)const
    {
        if(this->x != n1.x)
            return this->x < n1.x;
        return this->y > n1.y;
    }
};
int main()
{
    int s,n;
    cin>>s>>n;
    //int flag=0;
    vector<node> v;
    for(int i=0;i<n;i++)
    {
        node tmp;
        cin>>tmp.x>>tmp.y;
        v.pb(tmp);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++)
    {
        if(s>v[i].x)
            s+=v[i].y;
        else
        {
            cout<<"NO\n";
            return 0;
        }
    }
    cout<<"YES\n";
    return 0;
}