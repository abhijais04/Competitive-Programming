#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
int a[100100];
struct node
{
    int val;
    bool operator<(const node &n1)const
    {
        return this->val%10 > n1.val%10;
    }
};
vector<node> v;
int main()
{
    int n,k;
    cin>>n>>k;
    ll ans=0;
    ll rem=0;
    for(int i=0;i<n;i++)
        {
            cin>>a[i];
            ans+=(a[i]/10);
            if(a[i]%10!=0)
            {
                rem+=(100-a[i])/10;
                node tmp;
                tmp.val=a[i];
                v.pb(tmp);
            }
            else
            {

                rem+=((100-a[i])/10);
            }
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++)
        {
           // cout<<v[i].val<<"\n";
            if(k<=0)
                break;
            if(k>=(10-v[i].val%10))
            {
                k-=(10-v[i].val%10);
                ans++;
            }
            else
                break;
        }
        ans+=min(rem,(ll)k/10);
        cout<<ans<<"\n";
    return 0;
}