#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define MOD 1000000007
#define LIMIT 200000
using namespace std;
typedef long long ll; typedef long double ld; typedef unsigned long long ull;
typedef vector<int> vi; typedef pair<int, int> ii; typedef vector<pair<int, int> > vii; typedef vector< vector< pair<int, int> > > vvii;
typedef vector< vector < int > > vvi; typedef vector< bool > vb;
template <class T>
inline void ri(T &i){
	char c; for (c = getchar(); c<'0' || c>'9'; c = getchar());
	for (i = 0; c >= '0'&&c <= '9'; c = getchar())
		i = (i << 3) + (i << 1) + (c - 48);
}
int main()
{
    int n;
    ri(n);
    long long a[n];
    int i,j,k;
    for(i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    vector<long long >v1,v2;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
            {
                v1.pb((a[i]*a[j])+a[k]);
            }
        }
    }
    sort(v1.begin(),v1.end());
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
            {
                if(a[k]!=0)
                v2.pb((a[i]+a[j])*a[k]);
            }
        }
    }
    sort(v2.begin(),v2.end());
    long long ans=0;
    for(i=0;i<v1.size();i++)
    {
        long long t1=upper_bound(v2.begin(),v2.end(),v1[i])-lower_bound(v2.begin(),v2.end(),v1[i]);
        //if(t1!=v2.end())
        if(t1>0)
            ans+=t1;
    }
    cout<<ans<<"\n";
}
