#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
struct node
{
    int idx,val;
    bool operator<(const node n1)const
    {
        return this->val < n1.val;
    }
};
int a[100010],b[100010],p[100010],c[100010];
vector<node> v;
int main()
{
    int n,l,r;
    cin>>n;
    cin>>l>>r;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
        node tmp;
        tmp.idx=i;
        tmp.val=p[i];
        v.pb(tmp);
    }
    sort(v.begin(),v.end());
    int flag=1;
    int preci=INT_MIN;
    for(int i=0;i<v.size();i++)
    {
        int j=v[i].idx;
        int val=v[i].val;
        if(i>0)
        {
            if(v[i].val==v[i-1].val)
            {
                flag=0;
                break;
            }
        }
        int tmp=a[j];
        if(preci==INT_MIN)
        {
            b[j]=l;
            preci=b[j]-a[j];
        }
        else
        {
            int tt=a[j]+preci;
            tt++;
            tt=max(l,tt);
            if(tt>r)
            {
                //cout<<i<<" "<<a[j]<<" "<<tt<<"\n";
                flag=0;
                break;
            }
            b[j]=tt;
            preci=b[j]-a[j];
        }

    }
    if(flag==0)
    {
        cout<<"-1\n";
    }
    else
    {
        for(int i=0;i<n;i++)
            cout<<b[i]<<" ";
        cout<<"\n";
    }
    return 0;
}