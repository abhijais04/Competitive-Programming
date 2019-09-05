#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
vector<pair<string,int> > v;
int main()
{
    ios_base::sync_with_stdio(NULL);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string a,b;
        cin>>a>>b;
        v.pb({a,i+1});
        v.pb({b,i+1});
    }
    sort(v.begin(),v.end());
    int a[n];
    for(int k=0;k<n;k++)
        cin>>a[k];
    int i=0;
    int cnt=0;
   // for(int k=0;k<2*n;k++)
     //   cout<<v[k].first<<" "<<v[k].second<<"\n";
    for(int j=0;j<n;j++)
    {
        //a[j];
        if(n-cnt>2*n-j)
            break;
        while(i<2*n)
        {
            int tmp=v[i].second;
            if(tmp==a[j])
                {
                    cnt++;
                    i++;
                    break;
                }
                i++;
        }
        if(cnt==n)
            break;

    }
    if(cnt==n)
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}