#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int idx[200100];
bool ps[200100];
int n,m;
string a,b;
bool check(int h)
{
    for(int i=1;i<=n;i++)
        ps[i]=true;
    for(int i=1;i<=h;i++)
        ps[idx[i]]=false;
    int i=0,j=0;
    for(int j=0;j<m;j++)
    {
        int f=0;
        for(i;i<n;i++)
        {
            if(ps[i+1]==true)
            {
                if(a[i]==b[j])
                {
                    i++;
                    f=1;
                    //i++;
                    break;
                }
            }
        }
        if(f==0)
            return false;
    }
    return true;
}
int main()
{
    //string a,b;
    cin>>a>>b;
    n=a.length();
    m=b.length();
    for(int i=1;i<=n;i++)
        {
            cin>>idx[i];
        }
   int h=n-m;
   int l=1;
   int mid;
   if(check(h)==true)
   {
       cout<<h<<"\n";
       return 0;
   }
   if(check(1)==false)
   {
       cout<<"0\n";
       return 0;
   }
   int ans=0;
   while(l<h)
   {
       mid=(l+h)/2;
       //cout<<l<<" "<<h<<" "<<mid<<"\n";
       if(l+1==h)
       {
           if(check(h)==true)
            cout<<h<<"\n";
           else
            cout<<l<<"\n";
           return 0;
       }
       if(check(mid)==true)
       {
          // cout<<"mid "<<mid<<"\n";
           ans=mid;
           l=mid;
       }
       else
        h=mid-1;
        if(l==h)
        {
            cout<<l<<"\n";
            return 0;
        }
   }
   cout<<ans<<"\n";
    return 0;
}