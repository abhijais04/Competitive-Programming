#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
struct node
{
    ll x,y,idx;
    bool operator< (const node n1)const
    {
        if(this->y != n1.y)
            return this->y < n1.y;
        return this->x < n1.x;
    }
};
node pivot;
ll leftturn(node a,node b,node c)
{
    ll tmp = (c.y-b.y)*(b.x-a.x) - (c.x-b.x)*(b.y-a.y);
    if(tmp>0)
        return -1;
    if(tmp<0)
        return 1;
    return 0;
}
ll dst(node a,node b)
{
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}
bool comp(node a,node b)
{
    ll tmp = leftturn(pivot,a,b);
    if(tmp==0)
        return dst(pivot,a) < dst(pivot,b);
    return (tmp==-1);
}
map<pair<ll,ll>,ll> mp;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        mp.clear();
        ll n;
    cin>>n;
    vector<node> v;
    v.clear();
   // ll cnt=0;
    for(ll i=0;i<n;i++)
    {
        ll x,y;
        cin>>x>>y;
        node tmp;
        tmp.x=x;
        tmp.y=y;
        if(mp.count({x,y})==0)
        {
            //cnt++;
        tmp.idx=i+1;
        //cnt++;
        v.pb(tmp);
        }
        mp[{x,y}]++;
    }
    n=v.size();
    sort(v.begin(),v.end());
    pivot = v[0];
    sort(v.begin()+1,v.end(),comp);
    vector<node> tv;
    tv.pb(v[0]);
    for(ll i=1;i<v.size();)
    {
        //tv.pb(v[i]);
        node ttt=v[i];
        i++;
        while(i<n&&leftturn(pivot,v[i],ttt)==0)
           {
               //cout<<i<<" "<<leftturn(pivot,v[i],ttt)<<" \n";
                i++;
           }
        i--;
        //cout<<i<<"\n";
        tv.pb(v[i]);
        i++;
    }
    v=tv;
    n=v.size();
    stack<node> st;
    float ans=0;
    if(n==1)
    {
        cout<<"0.00"<<endl;
        cout<<"1"<<endl;
        cout<<endl;
        continue;
    }
    else if(n==2)
    {
        node tt=v[0];
        node tmp=v[1];
        ans=ans+(float)sqrt((float)((tt.x-tmp.x)*(tt.x-tmp.x))+(float)((tt.y-tmp.y)*(tt.y-tmp.y)));
        ans=ans+ans;
        printf("%.2f\n",ans);
        //cout<<setprecision(4)<<ans<<"\n";
        cout<<v[0].idx<<" "<<v[1].idx<<"\n";
        cout<<"\n";
        continue;

    }

    st.push(v[0]);
    st.push(v[1]);
    st.push(v[2]);
    for(ll i=3;i<v.size();i++)
    {
        node top = st.top();
        st.pop();
        while(!st.empty()&&leftturn(st.top(),top,v[i])!=-1)
        {
            top=st.top();
            st.pop();
        }
        st.push(top);
        st.push(v[i]);
    }
    vector<node> sol;
    sol.clear();

    while(!st.empty())
    {
        node tmp=st.top();
        st.pop();
        if(sol.size()>0)
        {
            node tt=sol[sol.size()-1];
            ans=ans+(float)sqrt((float)((tt.x-tmp.x)*(tt.x-tmp.x))+(float)((tt.y-tmp.y)*(tt.y-tmp.y)));
        }
        sol.pb(tmp);
        //cout<<tmp.x<<" "<<tmp.y<<"\n";
    }
    if((ll)sol.size()>2)
    {
        ll nn=sol.size();
        node tmp=sol[0];
        node tt=sol[nn-1];
        ans=ans+(float)sqrt((float)((tt.x-tmp.x)*(tt.x-tmp.x))+(float)((tt.y-tmp.y)*(tt.y-tmp.y)));
        printf("%.2f\n",ans);
        //cout<<setprecision(4)<<ans<<"\n";
        for(ll i=sol.size()-1;i>=0;i--)
            cout<<sol[i].idx<<" ";
        cout<<endl;
    }
    else
    {
        cout<<"0.00"<<endl;
        cout<<"1"<<endl;
    }
    cout<<endl;
    }

    return 0;
}
