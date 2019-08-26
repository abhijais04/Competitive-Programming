#include <bits/stdc++.h>
using namespace std;
#define ll long long
inline ll read()
{
  ll ret = 0;
   ll c = getchar_unlocked();
  while(c<'0' || c>'9')
    c = getchar_unlocked();
  while(c>='0' && c<='9')
  {
    ret = (ret<<3) + (ret<<1) + c - '0';
    c = getchar_unlocked();
  }
        return ret;
}
int main()
{
    while(1)
    {
        int n;
        cin>>n;
        if(n==0)
        break;
        cout<<(1+(n*(3*n+5))/2)<<"\n";
    }
    return 0;
}