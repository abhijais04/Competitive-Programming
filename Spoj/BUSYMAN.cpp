#include <bits/stdc++.h>
using namespace std;
int main()
{
   // ios::sync_with_stdio(false);
    //cin.tie(null);
    int t;
    cin>>t;
    while(t--)
    {
        int n,i;
        cin>>n;
        vector <pair <int,int> >v;
        for(i=0;i<n;i++)
        {
            int s,f;
            scanf("%d%d",&s,&f);
            v.push_back({f,s});
        }
        sort(v.begin(),v.end());
        int c=1;
        int p=v[0].first;
        for(i=1;i<n;i++)
        {
            if(v[i].second>=p)
            {
                c++;
                p=v[i].first;
            }
        }
        cout<<c<<"\n";
    }
    return 0;
}
