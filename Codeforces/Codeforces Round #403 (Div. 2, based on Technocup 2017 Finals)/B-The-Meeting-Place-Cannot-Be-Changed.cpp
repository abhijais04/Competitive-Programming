#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
struct node
{
    double x,vl;
    node () {}
    node(double _x,double _v)
    {
        x=_x;
        vl=_v;
    }
    bool operator<(node n1)const
    {
        return this->x < n1.x;
    }
};
vector<node> v;
double check(double x)
{
    double ans=INT_MIN;
    for(int i=0;i<v.size();i++)
    {
        double txx = v[i].x - x;
        if(txx<0)
            txx = -txx;
        ans=max(ans,(txx/v[i].vl));
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    double mn=INT_MAX,mx=INT_MIN;
    for(int i=0;i<n;i++)
    {
        double tx;
        cin>>tx;
        v.pb(node(tx,0.0));
        mn = min(mn,tx);
        mx=max(mx,tx);
    }
    for(int i=0;i<n;i++)
    {
        cin>>v[i].vl;
    }
    //sort(v.begin(),v.end());
    double mid;
    double ans=INT_MAX;
    while((mx-mn)>=1e-7)
    {
        mid = (double)(mx+mn)/((double)2.0);
        double t1 = check(mid);
        double t2 = check((mid+0.0000001));
        double t3 = check((double)(mid-0.0000001));
        if(t3>t1 && t2<t1)
        {
            ans = min(ans,t2);
            mn = mid;
        }
        else if(t2>t1 && t3<t1)
        {
            ans=min(ans,t3);
            mx=mid;
        }
        else
        {
            ans=t1;
            break;
        }
    }
    ans=min(ans,check(mx));
    cout<<setprecision(7)<<ans<<"\n";
    return 0;

}