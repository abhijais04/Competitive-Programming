#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sc(x) scanf("%d",&x)
int cnt;
vector<vector<int> > v;
int main()
{
    int n,m;
    sc(n); sc(m);
    cnt=0;
    n = (1LL<<n);
    for(int i=1;(n/i)>=1;i*=2)
    {
        cnt++;
        vector<int> tmp(n/i,0);
        v.pb(tmp);
    }
    for(int i=0;i<n;i++) sc(v[0][i]);

    for(int i=1;i<cnt;i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            if(i&1)
            v[i][j] = v[i-1][j*2]|v[i-1][(2*j)+1];
            else
            v[i][j] = v[i-1][j*2]^v[i-1][(2*j)+1];
        }
    }
    while(m--)
    {
        int p,x;
        sc(p); sc(x);
        p--;
        v[0][p]=x;
        p/=2;
        for(int i=1;i<cnt;i++)
        {
            if(i&1)
            v[i][p] = v[i-1][p*2]|v[i-1][(2*p)+1];
            else
            v[i][p] = v[i-1][p*2]^v[i-1][(2*p)+1];
            p/=2;
        }
        cout<<v[cnt-1][0]<<"\n";
    }
    return 0;
}