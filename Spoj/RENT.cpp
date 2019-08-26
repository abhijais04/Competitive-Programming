#include <bits/stdc++.h>
using namespace std;
struct node
{
    int st,du,price;
    bool operator<(const node n2) const
    {
        if(this->st!=n2.st)
        {
            return this->st < n2.st;
        }
        else
            return this->du < n2.du;
    }
};
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,i;
        cin>>n;
        vector <node>v;
        for(i=0;i<n;i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            //cin>>a>>b>>c;
            node tmp;
            tmp.st = a;
            tmp.price=c;
            tmp.du = b;
            v.push_back(tmp);
        }
        sort(v.begin(),v.end());
        int ar[n];
        for(i=0;i<n;i++)
        {
            ar[i] = v[i].st;
        }
        int dp[n+1];
        dp[n]=0;
        for(i=n-1;i>=0;i--)
        {
            int tmp = v[i].st + v[i].du;
            int idx = upper_bound(ar,ar+n,tmp) - ar;
            dp[i] = max(dp[i+1],v[i].price + dp[idx]);
        }
        printf("%d\n",dp[0]);
        //cout<<dp[0]<<"\n";

    }
}
