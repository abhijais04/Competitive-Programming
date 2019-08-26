#include<bits/stdc++.h>
using namespace std;
struct node
{
    long long mx,smx;

};
long long ar[100010];
node tree[2000010];
node mn={-1010,-1010};
node mrge(node a,node b)
{
    node tmp;
    if(a.mx>b.mx)
    {
        tmp.mx=a.mx;
        tmp.smx=max(a.smx,max(b.mx,b.smx));
    }
    else
    {
        tmp.mx=b.mx;
        tmp.smx=max(b.smx,max(a.mx,a.smx));
    }
    return tmp;
}
void build(long long tl,long long tr,long long n)
{
    if(tl>tr)
        return ;
    //cout<<n<<"\n";
    long long mid=(tl+tr)/2;
    if(tl==tr)
        {
            tree[n].mx=ar[tl];
            tree[n].smx=-1;
            return;
        }
    build(tl,mid,2*n);
    build(mid+1,tr,1+(2*n));
   // cout<<"build merge : - "<<n<<"\n";
    tree[n]=mrge(tree[2*n],tree[1+(2*n)]);
    return ;
}
node query(long long tl,long long tr,long long l,long long r,long long n)
{
    if(l>r||tl>tr)
        return mn;
    if(l==tl&&r==tr)
    {
        return tree[n];
    }
    long long mid=(tl+tr)/2;
    if(mid<l)
        return query(mid+1,tr,l,r,1+2*n);
    if(mid>=r)
        return query(tl,mid,l,r,2*n);
    return mrge(query(tl,mid,l,mid,2*n),query(mid+1,tr,mid+1,r,1+(2*n)));
}
void update(long long tl,long long tr,long long pos,long long val,long long n)
{
    if(tl>tr||tl>pos||tr<pos)
        return ;
    long long mid=(tl+tr)/2;
    if(tl==tr)
    {
        tree[n].mx=val;
        tree[n].smx=-1;
        return ;
    }
    update(tl,mid,pos,val,2*n);
    update(mid+1,tr,pos,val,1+(2*n));
    tree[n]=mrge(tree[2*n],tree[1+(2*n)]);
    return ;
}
int main()
{

    long long na,m;
    scanf("%lld",&na);
    long long i;
    ar[0]=0;
    for(i=1;i<=na;i++)
        scanf("%lld",&ar[i]);
    build(1,na,1);
    scanf("%lld",&m);
    while(m--)
    {
        string str;
        cin>>str;
        long long x,y;
        cin>>x>>y;
        if(str[0]=='U')
        {
            update(1,na,x,y,1);
        }
        else
        {
            node tmp=query(1,na,x,y,1);
            printf("%lld\n",tmp.mx+tmp.smx);
        }

    }
    return 0;
}
