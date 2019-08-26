#include <bits/stdc++.h>
using namespace std;
int ar[200010];
int tree[800040];
int lazy[800040];
int n;
void build(int tl,int tr,int node)
{
    if(tl>tr)
        return ;
    int mid=(tl+tr)/2;
    if(tl==tr)
    {
        tree[node]=0;
        return ;
    }
    build(tl,mid,2*node);
    build(mid+1,tr,1+(2*node));
    tree[node]=tree[2*node]+tree[(2*node)+1];
    return ;
}
int query(int tl,int tr,int l,int r,int node)
{
	
	 if(tl>r||tr<l||tl>tr)
        return 0;
    if(lazy[node]!=0)
    {
        if(lazy[node]%2==1)
        {
           tree[node] = (tr-tl+1 - tree[node]);
        }
        if(tl!=tr)
        {
            lazy[2*node]+=lazy[node];
            lazy[1+(2*node)]+=lazy[node];
        }
        lazy[node]=0;
    }
   
    if(tl>=l&&tr<=r)
        return tree[node];
    int mid=(tl+tr)/2;
    return (query(tl,mid,l,r,2*node)+query(mid+1,tr,l,r,(2*node)+1));
}
void update(int tl,int tr,int l,int r,int node)
{
    if(lazy[node]!=0)
    {
        if(lazy[node]%2==1)
        {
           tree[node] = (tr-tl+1-tree[node]);
        }
        if(tl!=tr)
        {
            lazy[2*node]+=lazy[node];
            lazy[1+(2*node)]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(tl>r||tr<l||tl>tr)
        return ;
    if(tl>=l&&tr<=r)
    {
       tree[node]  =  (tr-tl+1 - tree[node]);//update
        if(tl!=tr)
        {
            lazy[node*2]+=1;
            lazy[1+(node*2)]+=1;
        }
        return ;
    }
    int mid=(tl+tr)/2;
    update(tl,mid,l,r,2*node);
    update(mid+1,tr,l,r,(2*node)+1);
    tree[node]=tree[2*node]+tree[1+(2*node)]; //merge
    return ;
}
int main()
{
    ios_base::sync_with_stdio(false); 
cin.tie(NULL); 
cout.tie(NULL);
	int q;
    cin>>n>>q;
   // int i;
    build(1,n,1);
    memset(lazy, 0, sizeof lazy);
    int flag=0;
    while(q--)
    {
        int p,a,b;
        cin>>p>>a>>b;
        if(p==0)
            update(1,n,a,b,1);
        else if(p==1)
        cout<<query(1,n,a,b,1)<<"\n";
    }
    return 0;
}
