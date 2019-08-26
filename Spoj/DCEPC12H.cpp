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
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
      float n,k;
      cin>>n>>k;
      printf("%.7f\n",(n+1)/2.0);
    }
    return 0;
}
