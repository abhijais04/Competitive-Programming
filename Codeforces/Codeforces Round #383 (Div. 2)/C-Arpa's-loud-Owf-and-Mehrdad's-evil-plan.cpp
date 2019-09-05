#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define si(X) scanf("%d", &(X))
#define sll(X) scanf("%lld",&(X))
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define pb push_back
ll gcd(ll a,ll b){
	if(b==0)
	return a;
	return gcd(b,a%b);
}
string toBin(ll a) {
	string res = "";
	while (a) {
		res += char((a & 1) + '0');
		a >>= 1;
	}
	reverse(res.begin(), res.end());
	return res;
}
const int mod = 1e9+7;
ll expo(ll base,ll pow){
    ll ans = 1;
    while(pow!=0){
        if(pow&1==1){
            ans = ans*base;
            ans = ans%mod;
        }
        base *= base;
        base%=mod;
        pow/=2;
    }
    return ans;
}
ll inv(ll x){
    return expo(x,mod-2);
}
bool isPal(string ss){
    int len = ss.length();
    for(int i = 0 ; i<len/2 ; i++){
	int comp = len-i-1;
	if(ss[i]!=ss[comp])
		return false;
	}
    return true;
}
double pi = 3.141592653589793238462643;
double error = 0.0000001;
/* -------Template ends here-------- */
int visited[100010];
vector<int> v[100010];
int dfs(int x)
{
    if(visited[x]==1)
    {
        return 0;
    }
    visited[x]=1;
    int ans=0;
    for(int i=0;i<v[x].size();i++)
    {
        int y = v[x][i];
        if(visited[y]==false)
        {
            ans+=dfs(y);
        }
    }
    return ans+1;
}
int lcm(int a,int b)
{
    int tmp = gcd(a,b);
    return a*b/tmp;
}
int main()
{
    int n;
    cin>>n;
    set<int> s;
    for(int i=0;i<n;i++)
    {
        int tmp;
        cin>>tmp;
        v[i+1].pb(tmp);
        s.insert(tmp);
    }
    if(s.size()<n)
    {
        cout<<"-1";
        return 0;
    }
    int ans=1;
    for(int i=0;i<n;i++)
    {
        if(visited[i]==false)
        {
            int tmp=dfs(i);
            if(tmp&1)
            ans = lcm(ans,tmp);
            else
                ans=lcm(ans,tmp/2);
        }
    }
    cout<<ans<<"\n";
}