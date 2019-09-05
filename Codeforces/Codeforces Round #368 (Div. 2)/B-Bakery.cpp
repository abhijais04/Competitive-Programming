#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
vector<int> v[100010];
bool isk[100010];
struct node
{
    int a,b,c;

};
vector<node> ar;
int main()
{
ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    ll n,m,k;
    ll i,j;
    cin>>n>>m>>k;
    for(i=0;i<m;i++)
    {
        ll a,b,c;
        cin>>a>>b>>c;
         node tmp;
        tmp.a=a;
        tmp.b=b;
        tmp.c=c;
        ar.pb(tmp);
    }
    for(i=0;i<k;i++)
    {
        ll a;
        cin>>a;
        isk[a]=true;
    }
    ll mn=INT_MAX;
    for(i=0;i<m;i++)
    {
        node tmp=ar[i];
        ll a=tmp.a,b=tmp.b,c=tmp.c;
        if(isk[a]==true||isk[b]==true)
        {
            if(!(isk[a]&&isk[b]))
            {
                mn = min(mn,c);
            }
        }
    }
    if(mn<INT_MAX)
      cout<<mn<<"\n";
    else
       cout<<"-1\n";
    return 0;
}