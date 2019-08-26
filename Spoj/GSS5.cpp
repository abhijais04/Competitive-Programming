#include<bits/stdc++.h>
using namespace std;
struct node
{
    long long sum,best,lbest,rbest;

};
node tree[200000];
long long ar[100000];
node mn={0,0,0,0};
node mn2={0,-10000000,-10000000,-10000000};
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
void build(long long tl,long long tr,long long n)
{
    if(tl>tr)
        return ;
    //cout<<n<<"\n";
    long long mid=(tl+tr)/2;
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
node query(long long tl,long long tr,long long l,long long r,long long n)
{
    if(l>r||tl>tr)
        return mn;
   // cout<<n<<"\n";
    if(l==tl&&r==tr)
    {
       // cout<<"return "<<n<<"\n";
        //cout<<tree[n].best<<"\n";
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
    long long te;
    cin>>te;
    while(te--)
    {
        long long na,m;
    scanf("%lld",&na);
    long long i;
    ar[0]=0;
    for(i=1;i<=na;i++)
        scanf("%lld",&ar[i]);
    build(1,na,1);
    //cout<<"sad "<<tree[2].best<<"\n";
    scanf("%lld",&m);
    while(m--)
    {
        long long x1,y1,x2,y2;
        long long ans;
        scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
           if(x2==y1)
           {
                node tmp1 = query(1,na,x1,y1-1,1);
                node tmp2= query(1,na,x2+1,y2,1);
                node tmp3;
                //if(x2>y1+1)
                tmp3 = query(1,na,y1,x2,1);
                //else
                //tmp3=mn2;
                ans = tmp3.sum;
               // cout<<ans<<"\n";
                ans=max(ans+tmp2.sum+tmp1.sum,max(ans+tmp2.lbest+tmp1.sum,ans+tmp1.rbest+tmp2.sum));
                ans=max(ans,tmp3.sum+tmp2.lbest+tmp1.rbest);
                ans=max(ans,max(tmp3.sum,max(tmp3.sum+tmp2.lbest,tmp3.sum+tmp1.rbest)));
           }
           else if(x2>y1)
            {
                node tmp1 = query(1,na,x1,y1,1);
                node tmp2= query(1,na,x2,y2,1);
                node tmp3;
                if(x2>y1+1)
                tmp3 = query(1,na,y1+1,x2-1,1);
                else
                tmp3=mn2;
                ans = tmp3.sum;
               // cout<<ans<<"\n";
                ans=max(ans+tmp2.sum+tmp1.sum,max(ans+tmp2.lbest+tmp1.sum,ans+tmp1.rbest+tmp2.sum));
                ans=max(ans,tmp3.sum+tmp2.lbest+tmp1.rbest);
            }
            else
            {
                node tmp2 = query(1,na,x2,y1,1);
               // cout<<tmp2.best<<"\n";
                node tmp1,tmp3;
                if(x2>x1)
                 tmp1 = query(1,na,x1,max(x1,x2-1),1);
                else
                    tmp1=mn2;
                if(y2>y1)
                 tmp3 = query(1,na,min(y1+1,y2),y2,1);
                else
                    tmp3=mn2;
               // long long x=max(tmp1.sum,tmp1.rbest);
                //long long y=max(tmp3.sum,tmp3.lbest);
               // long long z=tmp2.sum;
               // ans=max(z+max(x,y),z+x+y);
                //ans=max(ans,max(tmp2.lbest+tmp1.rbest,tmp2.rbest+tmp3.lbest));
                node tmp4=query(1,na,x1,y1,1);
                node tmp5=query(1,na,x2,y2,1);
                ans=max(tmp1.rbest+tmp5.lbest,tmp4.rbest+tmp3.lbest);
               // cout<<tmp2.best<<"\n";
                ans=max(ans,tmp2.best);


            }
            printf("%lld\n",ans);

        }
    }
    return 0;
}
