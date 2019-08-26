#include <bits/stdc++.h>
using namespace std;
struct node
{
    long long lc,rc;
    long long nl,nr;
    node()
    {
        this->lc=-1;
        this->rc=-1;
        this->nl=0;
        this->nr=0;
    }

};
node ar[4000000];
long long nodes=1;
void add(long long x)
{
    long long cn=0;
    for(int i=31;i>=0;i--)
    {
        bool b= (1<<i)&x;
        if(b==1)
        {
            ar[cn].nr++;
            if(ar[cn].rc==-1)
            {
                ar[cn].rc=nodes;
                nodes++;
            }
                cn=ar[cn].rc;
        }
        else
        {
            ar[cn].nl++;
            if(ar[cn].lc==-1)
            {
                ar[cn].lc=nodes;
                nodes++;
            }
            cn=ar[cn].lc;
        }
    }
}
long long query(int q,int k)
{
    long long ans=0;
    long long cn=0,i;
    for(i=31;i>=0;i--)
    {
        bool a1,a2;
        a1=((1<<i)&q);
        a2=((1<<i)&k);
        if(a1==0)
        {
            if(a2==0)
            {
                if(ar[cn].lc!=-1)
                cn=ar[cn].lc;
                else
                    break;
            }
            else
            {
                ans+=ar[cn].nl;
                if(ar[cn].rc!=-1)
                cn=ar[cn].rc;
                else
                    break;
            }
        }
        else
        {
            if(a2==0)
            {
                //ans+=ar[cn].nl;
                if(ar[cn].rc!=-1)
                cn=ar[cn].rc;
                else
                    break;
            }
            else
            {

                ans+=ar[cn].nr;
                if(ar[cn].lc!=-1)
                cn=ar[cn].lc;
                else
                    break;
            }
        }
    }
    return ans;
}
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
    long long n,i,k;
    cin>>n>>k;
    for(i=0;i<32*n;i++)
    {
        {
        ar[i].lc=-1;
        ar[i].rc=-1;
        ar[i].nl=0;
        ar[i].nr=0;
        }
    }
    long long a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
   long long tmp=0;
   add(0);
   long long ans=0;
   for(i=0;i<n;i++)
   {
       tmp=tmp^a[i];
       ans+=query(tmp,k);
       add(tmp);
   }
   cout<<ans<<"\n";
   }
    return 0;
}
