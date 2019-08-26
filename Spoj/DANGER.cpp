#include <bits/stdc++.h>
using namespace std;
int fun(int c,int n)
{
    if(c==1)
    {
        if(n&1)
            return 2;
        return 1;
    }
    else
    {
        if(n&1)
            return 1;
        return 2;
    }
}
int main()
{
  while(1)
  {
      char ch[12];
      scanf("%s",&ch);
   //   cout<<ch<<"\n";
      int n=((ch[0]-'0')*10)+(ch[1]-'0');
      n=n*pow(10,ch[3]-'0');
      if(n==0)
        break;
      int first=1,last=n;
    int  c=fun(2,n);
     if(n%2==0)
      last=n-1;
      if(n%2==1)
        n=(n/2)+1;
      else
        n=n/2;
      int i=1;
    while(first<last)
    {
        if(c==1)
            {
                    first+=(1<<i);
                    if(n%2==1)
                        last-=(1<<i);
            }
        else
            {
                if(n%2==0)
                    last-=(1<<i);
            }
        int tmp=c;
        c=fun(c,n);
        if(n&1)
            {
                n=(n/2);
                if(tmp==2)
                    n++;
            }
        else
            n=n/2;
            if(first==last)
            break;
        i++;

    }
    cout<<first<<"\n";
  }
    return 0;
}
