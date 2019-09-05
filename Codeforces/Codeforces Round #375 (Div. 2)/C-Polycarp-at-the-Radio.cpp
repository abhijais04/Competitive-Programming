#include<bits/stdc++.h>
using namespace std;
map<long long,int> mp;
long long pl[2010];
int cnt[2010];
int sang[2010];
long long a[2010];
int main()
{
    long long n,m;
    long long i;
    cin>>n>>m;
    for(i=0;i<n;i++)
        {
            cin>>a[i];
            mp[a[i]]++;
        }
    int mx=n/m;
    list<long long> q;
    for(i=1;i<=m;i++)
        {
            if(mp.count(i)!=0)
            cnt[i]=mx-mp[i];
            else
                cnt[i]=mx;
            if(cnt[i]>0)
                q.push_back(i);

            sang[i]=0;
        }

    map<long long,int> ::iterator it;
    int mn=0;
    long long ans=0;
    for(i=1;i<=m;i++)
    {
        if(mp.count(i)!=0)
        {
            if(mp[i]<mx)
                ans+=mx-mp[i];
        }
        else
            ans+=mx;
    }
    cout<<mx<<" "<<ans<<"\n";
    for(i=0;i<n;i++)
    {
        long long band = a[i];
        if(a[i]<=m)
        {
            if(sang[band]<mx)
            {
                cout<<band<<" ";
                sang[band]++;
            }
            else
            {
                if(!q.empty())
                {
                    int ff = q.front();
                    cout<<ff<<" ";
                    cnt[ff]--;
                    if(cnt[ff]==0)
                        q.pop_front();
                    sang[ff]++;
                }
                else
                {
                    cout<<band<<" ";
                }
            }

        }
        else
        {
                if(!q.empty())
                {
                    int ff = q.front();
                    cout<<ff<<" ";
                    cnt[ff]--;
                    if(cnt[ff]==0)
                        q.pop_front();
                    sang[ff]++;
                }
                else
                {
                    cout<<band<<" ";
                }
        }
    }
    cout<<"\n";

}