#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sc(x) scanf("%d",&x)
int z[400010];
vector<int> getdiff(vector<int> v)
{
    vector<int> ans;
    for(int i=1;i<v.size();i++)
    {
        ans.pb(v[i]-v[i-1]);
    }
    return ans;
}
void compute_z(vector<int> str,vector<int> pat)
{

    vector<int> s = pat;
    for(int i=0;i<str.size();i++)
    {
        s.pb(str[i]);
    }
    int n = s.size();
    int L = 0, R = 0;
    for (int i = 1; i < n; i++) {
    if (i > R) {
    L = R = i;
    while (R < n && s[R-L] == s[R]) R++;
    z[i] = R-L; R--;
  } else {
    int k = i-L;
    if (z[k] < R-i+1) z[i] = z[k];
    else {
      L = i;
      while (R < n && s[R-L] == s[R]) R++;
      z[i] = R-L; R--;
    }
  }
}
}
int main()
{
    int n,m;
    sc(n); sc(m);
    vector<int> str,pat;
    for(int i=0;i<n;i++)
    {
        int tmp; sc(tmp);
        str.pb(tmp);
    }
    for(int i=0;i<m;i++)
    {
        int tmp; sc(tmp);
        pat.pb(tmp);
    }
    if(m==1)
    {
        cout<<n<<"\n";
        return 0;
    }
    if(n<m)
    {
        cout<<"0\n";
        return 0;
    }
    str = getdiff(str);
    pat = getdiff(pat);

    compute_z(str,pat);
    int ans = 0;
    for(int i=m-1;i<m+n;i++)
    {
        if(z[i]>=m-1)
            ans++;
    }
    cout<<ans<<"\n";

}