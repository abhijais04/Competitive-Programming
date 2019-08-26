#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define gc getchar
//_unlocked
int read() {
  char c = gc();
  while(c<'0' || c>'9') c = gc();
  int ret = 0;
  while(c>='0' && c<='9') {
    ret = 10 * ret + c - 48;
    c = gc();
  }
  return ret;
}
 map  <int,int>mp,mark;
int main()
{
    int t;
    scanf("%d",&t);
    //cin>>t;
    while(t--)
    {
       mp.clear();
       mark.clear();
        int n,cnt=0,i;
        scanf("%d",&n);
        int a[n];
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            //cin>>a[i];
            mp[a[i]]++;
        }
        sort(a,a+n);
        for(i=0;i<n;i++)
        {
            if(mp.count(2*a[i])!=0&&mp.count(a[i])!=0)
            {
              //  cout<<a[i]<<" ";

                    cnt++;
                    if(mp[a[i]]==1)
                        mp.erase(mp.find(a[i]));
                    else
                        mp[a[i]]=mp[a[i]]-1;
                    if(mp[2*a[i]]==1)
                        mp.erase(mp.find(2*a[i]));
                    else
                    mp[2*a[i]] = mp[2*a[i]]-1;
                        //mp.erase(mp.find(2*a[i]));
            }
        }
        cout<<cnt<<"\n";
    }
    return 0;
}
