#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
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
            while(i>=0) putchar_unlocked(buffor[i--]);
            putchar_unlocked('\n');
       }
struct node
{
    int val,l,r,id,qn;
    node()
    {
        this->val=0;
        this->id=0;
        this->l=0;
        this->r=0;
        this->qn=0;
    }
    bool operator <(const node a)const
    {
        if(this->val!=a.val)
        return (this->val<a.val);
        else
        return (this->id<a.id);
    }
};
int a[2000010];
int mx_val;
void update(int idx,int val)
{
    while(idx<=mx_val)
    {
        a[idx]+=val;
        idx+=(idx&-idx);
    }
}
int getval(int idx)
{
    int ans=0;
    while(idx>0)
    {
        ans+=a[idx];
        idx=idx-(idx&-idx);
       // cout<<idx<<" ";
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    mx_val=n+1;
    int i;
    int t[n];
    vector <node>v;
    for(i=0;i<n;i++)
    {
        read(t[i]);
       // cin>>t[i];
        node tmp;
        tmp.val=t[i];
        tmp.id=1;
        tmp.l=i+1;
        tmp.r=i+1;
        tmp.qn=i+1;
        v.push_back(tmp);
    }
    int q;
    read(q);
    //cin>>q;
    for(i=0;i<q;i++)
    {
        int x,y,k;
        read(x);
        read(y);
        read(k);
     //   cin>>x>>y>>k;
        node tmp;
        tmp.id=2;
        tmp.l=x;
        tmp.r=y;
        tmp.val=k;
        tmp.qn=i;
        v.push_back(tmp);
    }
    //cout<<"asdas ";
    sort(v.begin(),v.end());
    vector <int>ans(q);
    for(i=v.size()-1;i>=0;i--)
    {
        node tmp=v[i];
        if(tmp.id==1)
        {
            //if(tmp.val>tmp.val)
            update(tmp.qn,1);
        }
        else
        {
            int y=getval(tmp.r)-getval((tmp.l)-1);
            ans[tmp.qn]=y;
        }
    }
    for(int i=0;i<q;i++)
    {
        write(ans[i]);
    //    puts("\n");
        //cout<<ans[i]<<"\n";
    }
    return 0;
}
