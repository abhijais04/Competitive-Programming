#include<bits/stdc++.h>
using namespace std;
struct node
{
    long long val,ind;

};
node mn={-100000,-100};
node tree[400010];
long long ar[200010],dp[200010];
node mrge(node a,node b)
{
    node tmp;
    if(a.val>b.val)
    {
        tmp=a;
    }
    else if(a.val<b.val)
    {
        tmp=b;
    }
    else
    {
        if(a.ind<b.ind)
            tmp=a;
        else
            tmp=b;
    }
    return tmp;
}
void build(long long tl,long long tr,long long n)
{
    if(tl>tr)
        return ;
    long long mid=(tl+tr)/2;
    if(tl==tr)
        {
            tree[n].val = ar[tl];
            tree[n].ind = tl;
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
int main()
{
    long long nn,i;
    cin>>nn;
    //long long a[nn-1];
    for(i=1;i<nn;i++)
    {
        cin>>ar[i];
    }
    build(1,nn,1);
    ar[nn]=0;
    dp[nn]=0;
    long long sum=0;
    for(i=nn-1;i>0;i--)
    {
        node tmp=query(1,nn,i+1,ar[i],1);
        long long m=tmp.ind;
        dp[i]=dp[m]-(ar[i]-m)+nn-(i);
        sum+=dp[i];
    }
    cout<<sum<<"\n";
    return 0;
}