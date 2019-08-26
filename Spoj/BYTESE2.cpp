#include<bits/stdc++.h>
using namespace std;
/*#define gc getchar_unlocked
int read_int() {
  char c = gc();
  while(c<'0' || c>'9') c = gc();
  int ret = 0;
  while(c>='0' && c<='9') {
    ret = 10 * ret + c - 48;
    c = gc();
  }
  return ret;
}*/
map <int,int>mp;
int main()
{
    int mx=0;
    int t;
    cin>>t;
    while(t--)
    {
        //for(int i=0;i<=mx;i++)
          //  ar[i]=0;
        int n,ans=0,sum=0;
        cin>>n;
        while(n--)
        {
            int a,b;
            cin>>a>>b;
            mp[a]=1;
            mp[b]=-1;
            //mx=max(mx,b);
        }
        for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++)
        {
            sum+=(it->second);
            ans=max(sum,ans);
        }
        cout<<ans<<"\n";
        mp.clear();
    }
    return 0;
}
