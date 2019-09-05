#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define mod 1000000007
ll l[101000],r[101000];
bool isvowel(char ch)
{
    if(ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U')
        return true;
    return false;
}
int main()
{
  ll n;
  cin>>n;
  ll sl=0,sr=0;
  for(int i=0;i<n;i++)
    {
        cin>>l[i]>>r[i];
        sl+=l[i];
        sr+=r[i];
    }
    ll pre = abs(sl-sr);
  ll ans=-1;
  for(int i=0;i<n;i++)
  {
      ll nl = sl-l[i]+r[i];
      ll nr = sr-r[i]+l[i];
      if(abs(nl-nr)>pre)
      {
          ans=i;
          pre = abs(nl-nr);
      }
  }
  cout<<ans+1<<"\n";


}