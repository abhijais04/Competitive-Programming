#include<bits/stdc++.h>
using namespace std;
#define ll int
#define pb push_back
int a[100010];
vector<int > f;
string ans;
int b[100010];
int fn(int l,int r,int t)
{
 //   cout<<l<<" "<<r<<" "<<t<<"\n";
    int mx=0;
    if(l==r)
        return 0;
    for(int i=l;i<=r;i++)
    {
        mx=max(mx,a[i]);
    }
    for(int i=l;i<=r;i++)
    {
        int x = i-l+t;
        if(a[i]==mx)
        {
            for(int j=i-1;j>=l;j--)
            {
                if(a[i]>a[j])
                {
                    a[i]+=a[j];
                   // cout<<x<<" L\n";
                    f.pb(x);
                    x--;
                    ans+='L';
                }
                else
                    break;
            }
            for(int j=i+1;j<=r;j++)
                {
                    if(a[i]>a[j])
                    {
                        a[i]+=a[j];
                        f.pb(x);
                        ans+='R';
                    }
                    else
                        break;
                }
                if(x==i-l+t)
        {
            for(int j=i-1;j>=l;j--)
            {
                if(a[i]>a[j])
                {
                    a[i]+=a[j];
                    f.pb(x);
                    x--;
                    ans+='L';
                }
            }
        }
        if(a[i]>mx)
            return 0;

        }

    }
    return -1;
}
int main()
{
    ll n;
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>a[i];
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
        cin>>b[i];
    int ff = 1;
    int l=1;
    vector<int> v;
    v.pb(0);
    for(int i=0;i<m;i++)
    {
        int sum=0;
        while(l<=n&&sum<b[i])
        {
            sum+=a[l];
            l++;
        }
        if(sum!=b[i])
        {
            ff=0;
            break;
        }
        else
        {
            v.pb(l-1);
        }
    }
    //cout<<l<<"\n";
    if(ff==1&&l>n)
    {
       // cout<<"sad\n";
        for(int i=0;i<v.size()-1;i++)
        {
            //cout<<"sad2\n";
            int tmp = fn(v[i]+1,v[i+1],i+1);
         //   cout<<i<<" dfg\n";
            if(tmp<0)
            {
                cout<<"NO\n";
                return 0;
            }
        }
        cout<<"YES\n";
        for(int i=0;i<f.size();i++)
        {
            cout<<f[i]<<" "<<ans[i]<<"\n";
        }
    }
    else
    {
        cout<<"NO\n";
        return 0;
    }
    return 0;
}