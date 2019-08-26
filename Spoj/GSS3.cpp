#include<bits/stdc++.h>
using namespace std;
struct node
{
    int sum,best,lbest,rbest;

};
node tree[200000];
int ar[100000];
node mn={0,-10000000,-10000000,-100000000};
node mrge(node a,node b)
{
   // if(a.sum==-1)

    node tmp;
    tmp.sum=a.sum+b.sum;
    tmp.lbest=max(b.lbest+a.sum,a.lbest);
    tmp.rbest=max(b.rbest,b.sum+a.rbest);
    tmp.best= max(max(max(a.rbest+b.lbest,max(b.rbest,a.lbest)),a.best),b.best);
    tmp.best=max(tmp.best,tmp.sum);
//    if(a.sum==-1&&b.sum==2)
 //   cout<<tmp.best<<"\n";
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
            tree[n].sum=ar[tl];
            tree[n].best=ar[tl];
            tree[n].lbest=ar[tl];
            tree[n].rbest=ar[tl];
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

   // cout<<n<<"\n";
    if(l==tl&&r==tr)
    {
       // cout<<"return "<<n<<"\n";
        //cout<<tree[n].best<<"\n";
        return tree[n];
    }
    int mid=(tl+tr)/2;
    if(mid<l)
        return query(mid+1,tr,l,r,1+2*n);
    if(mid>=r)
        return query(tl,mid,l,r,2*n);
    return mrge(query(tl,mid,l,mid,2*n),query(mid+1,tr,mid+1,r,1+(2*n)));
}
void update(int tl,int tr,int pos,int x,int n)
{
    if(tl>tr)
        return ;
    if(tl==tr)
    {
        tree[n].sum=x;
        tree[n].best=x;
        tree[n].lbest=x;
        tree[n].rbest=x;
        return;
    }
    int mid = (tl+tr)/2;
    if(pos>mid)
        update(mid+1,tr,pos,x,1+2*n);
    else
        update(tl,mid,pos,x,2*n);
    tree[n]=mrge(tree[2*n],tree[1+2*n]);
}
int main()
{
    int na,m;
    scanf("%d",&na);
    int i;
    ar[0]=0;
    for(i=1;i<=na;i++)
        scanf("%d",&ar[i]);
    build(1,na,1);
    //cout<<"sad "<<tree[2].best<<"\n";
    scanf("%d",&m);
    while(m--)
    {
        int t,x,y;
        scanf("%d%d%d",&t,&x,&y);
        if(t==1)
        {
            node tmp = query(1,na,x,y,1);
        //scout<<tmp.lbest<<" "<<tmp.rbest<<" "<<tmp.sum<<" "<<tmp.best<<"\n";
            printf("%d\n",tmp.best);
        }
        else
        {
            update(1,na,x,y,1);
        }

    }
    return 0;
}
