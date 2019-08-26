#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
int read_int() {
  char c = gc();
  while(c<'0' || c>'9') c = gc();
  int ret = 0;
  while(c>='0' && c<='9') {
    ret = 10 * ret + c - 48;
    c = gc();
  }
  return ret;
}
struct node
{
    int d[3];
    node()
    {
        d[0]=d[1]=d[2]=0;
    }
};
int ar[100010];
node tree[2000010];
int lazy[2000010];
node mn;

node mrge(node a,node b)
{
    node tmp;
    for(int i=0;i<3;i++)
    {
        tmp.d[i]=a.d[i]+b.d[i];
    }
    return tmp;
}
void build(int tl,int tr,int n)
{
    if(tl>tr)
        return ;
    //cout<<n<<"\n";
    int mid=(tl+tr)/2;
    if(tl==tr)
        {
           // int tmp=ar[tl]%3;
            tree[n].d[0]=1;
            return;
        }
    build(tl,mid,2*n);
    build(mid+1,tr,1+(2*n));
   // cout<<"build merge : - "<<n<<"\n";
    tree[n]=mrge(tree[2*n],tree[1+(2*n)]);
    return ;
}
node query(int tl,int tr,int l,int r,int n)
{
    if(lazy[n]!=0)
    {
        if((lazy[n]%3)!=0)
        {
            if(lazy[n]%3==1)
            {
                int tmp=tree[n].d[2];
                //a[1]=a[0];
                tree[n].d[2]=tree[n].d[1];
                tree[n].d[1]=tree[n].d[0];
                tree[n].d[0]=tmp;
            }
            else if(lazy[n]%3==2)
            {
                int tmp=tree[n].d[2];
                tree[n].d[2]=tree[n].d[0];
                tree[n].d[0]=tree[n].d[1];
                tree[n].d[1]=tmp;
            }
        }
        if(tl!=tr)
        {
            lazy[2*n]+=lazy[n];
            lazy[1+(2*n)]+=lazy[n];
        }
        lazy[n]=0;
    }
    if(r<tl||l>tr)
       return mn;
   //cout<<"query : "<<n<<"\n";
    if(l<=tl&&r>=tr)
    {
        return tree[n];
    }
    int mid=(tl+tr)/2;
    return mrge(query(tl,mid,l,r,2*n),query(mid+1,tr,l,r,1+(2*n)));
}
void update(int tl,int tr,int l,int r,int n)
{
    if(lazy[n]!=0)
    {
        if(lazy[n]%3!=0)
        {
            if(lazy[n]%3==1)
            {
                int tmp=tree[n].d[2];
                //a[1]=a[0];
                tree[n].d[2]=tree[n].d[1];
                tree[n].d[1]=tree[n].d[0];
                tree[n].d[0]=tmp;
            }
            else
            {
                int tmp=tree[n].d[2];
                tree[n].d[2]=tree[n].d[0];
                tree[n].d[0]=tree[n].d[1];
                tree[n].d[1]=tmp;
            }
        }
        if(tl!=tr)
        {
            lazy[2*n]+=lazy[n];
            lazy[1+(2*n)]+=lazy[n];
        }
        lazy[n]=0;
    }
    if(tl>tr||tl>r||tr<l)
        return ;
    int mid=(tl+tr)/2;
    if(tl>=l&&tr<=r)
    {
            int tmp=tree[n].d[2];
                //a[1]=a[0];
                tree[n].d[2]=tree[n].d[1];
                tree[n].d[1]=tree[n].d[0];
                tree[n].d[0]=tmp;

        if(tl!=tr)
        {
            lazy[2*n]++;
            lazy[1+(2*n)]++;
        }
        return ;
    }
    update(tl,mid,l,r,2*n);
    update(mid+1,tr,l,r,1+(2*n));
    tree[n]=mrge(tree[2*n],tree[1+(2*n)]);
    return ;
}
int main()
{
    mn.d[0]=mn.d[1]=mn.d[2]=0;
    int na,m;
    na=read_int();
    //scanf("%d",&na);
    int i;
    ar[0]=0;
    for(i=1;i<=na;i++)
        ar[i]=0;
    build(1,na,1);
    m=read_int();
    //scanf("%d",&m);
    while(m--)
    {
        int x,y,z;
        x=read_int();
        y=read_int();
        z=read_int();
     //   cin>>x>>y>>z;
        y++;
        z++;
        if(x==0)
        {
            update(1,na,y,z,1);
        }
        else
        {
            node tmp=query(1,na,y,z,1);
            printf("%d\n",tmp.d[0]);
        }
    }
    return 0;
}
