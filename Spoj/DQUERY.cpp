#include<bits/stdc++.h>
using namespace std;
#define gc getchar
//_unlocked
#define pc putchar
//_unlocked
inline void read(int &x){

        x=0;
        register char c=gc();
        for(;c<'0' || c>'9';c=gc());
         for(;c>='0' && c<='9';c=gc())
          x=(x<<3)+(x<<1)+(c-'0');
      }
      inline void write(int x){

         register char buffor[35];
         register int i=0;
         do{
               buffor[i++]=(x%10)+'0';
               x/=10;
            } while(x);
           i--;
            while(i>=0) pc(buffor[i--]);
            pc('\n');
       }
struct node
{
    int l,r,qn,bn;
    node()
    {
        this->l=0;
        this->r=0;
        this->qn=0;
        this->bn=0;
    }
    bool operator <(const node a)const
    {
        if(this->bn!=a.bn)
        return (this->bn<a.bn);
        else
        return (this->r<a.r);
    }
};
int ar[2000010];
int cnt[1000010];
int ans=0;
void add(int pos)
{
    cnt[ar[pos]]++;
    if(cnt[ar[pos]]==1)
        ans++;
}
void remove(int pos)
{
    //if(cnt[ar[pos]]>0)
    cnt[ar[pos]]--;
    if(cnt[ar[pos]]==0)
        ans--;
}
int main()
{
    int n;
    cin>>n;
    int sn=sqrt(n);
    int i;
    for(i=0;i<=1000002;i++)
    {
        cnt[i]=0;
    }
    vector <node>v;
    for(i=1;i<=n;i++)
    {
        read(ar[i]);
       // cin>>t[i];
    }
    int q;
    read(q);
    //cin>>q;
    for(i=0;i<q;i++)
    {
        int x,y;
        read(x);
        read(y);
        node tmp;
        tmp.l=x;
        tmp.r=y;
        tmp.bn=((x)/sn);
        tmp.qn=i;
        v.push_back(tmp);
    }
    //cout<<"asdas ";
    sort(v.begin(),v.end());
    vector <int>an(q);
    int cl=1,cr=0;
    for(i=0;i<q;i++)
    {
        node t=v[i];
        int l1=t.l,r1=t.r;
        while(cl<l1)
        {
            remove(cl);
            cl++;
        }
        while(cl>l1)
        {
            cl--;
            add(cl);

         }

        while(cr<r1)
        {
            cr++;
            add(cr);

        }
        while(cr>r1)
        {
            remove(cr);
            cr--;
        }
        cr=r1;
        cl=l1;
        //cout<<t.qn<<" "<<ans<<"\n";
        an[t.qn]=ans;
    }
    for(int i=0;i<q;i++)
    {
        write(an[i]);
    }
    return 0;
}
