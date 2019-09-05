#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
struct node
{
    string a,b;
    node() {}
    node(string _a,string _b)
    {
        a = _a;
        b = _b;
    //    c = _c;
    }
};
vector<node> v;
vector<string> ans;
set<string> use,ban;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string a,b;
        cin>>a>>b;
        string ta="",tb="";
        for(int i=0;i<3;i++)
        {
            ta+=a[i];
            if(i!=2)
                tb+=a[i];
            else
                tb+=b[0];
        }
        v.pb(node(ta,tb));
    }

    for(int i=0;i<n;i++)
    {
        if(use.count(v[i].b))
        {
            if((use.count(v[i].a))||ban.count(v[i].a))
            {
                cout<<"NO\n";
                return 0;
            }
            else
            {
                use.insert(v[i].a);
                ans.pb(v[i].a);
            }
        }
        else
        {
            use.insert(v[i].b);
            ban.insert(v[i].a);
            ans.pb(v[i].b);
        }
    }
    cout<<"YES\n";
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<"\n";
    }
}