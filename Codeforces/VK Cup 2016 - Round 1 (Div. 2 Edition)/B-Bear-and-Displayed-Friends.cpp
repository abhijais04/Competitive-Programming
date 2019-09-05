#include <bits/stdc++.h>
using namespace std;
bool a1[150011];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,i,j,q,k;
    cin>>n>>k>>q;
    int t[n+1];
    for(i=1;i<=n;i++)
        cin>>t[i];
    set <int>s;
    set<int>::iterator it;
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        if(a==1)
        {
            it=s.begin();
            if(s.size()<k)
                {
                    s.insert(t[b]);
                    a1[b]=true;
                }
            else
            {
                int tmp=*it;
                if(tmp<t[b])
                {
                    s.erase(it);
                    s.insert(t[b]);
                    a1[b]=true;
                }
            }
        }
        else
        {
            it=s.begin();
            int tmp=*it;
            if(t[b]>=tmp&&a1[b])
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
    }

    return 0;
}