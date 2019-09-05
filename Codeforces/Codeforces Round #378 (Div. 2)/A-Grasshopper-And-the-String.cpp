#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define mod 1000000007
bool isvowel(char ch)
{
    if(ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U'||ch=='Y')
        return true;
    return false;
}
int main()
{
  string str;
  cin>>str;
  int l = str.length(),i;
  int ans=1,pre=-1;
  for(i=0;i<l;i++)
  {
      if(isvowel(str[i]))
      {
          ans=max(ans,i-pre);
          pre=i;
      }
  }
  ans=max(ans,i-pre);
  cout<<max(1,ans)<<"\n";
  return 0;
}