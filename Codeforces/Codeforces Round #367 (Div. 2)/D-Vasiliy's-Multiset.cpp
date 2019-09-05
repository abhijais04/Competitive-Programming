#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll pw[100];
struct node
{
    node *lc,*rc;
    int cnt;
    node()
    {
        lc=NULL;
        rc=NULL;
        cnt=1;
    }
};
node *root=new node();
void add(ll k)
{
    node *tmp = root;
    for(ll i=31;i>=0;i--)
    {
        bool b = ((1<<i)&k);
         //if(b>0)
          //  b=1;
        if(b==1)
        {
            if(tmp->rc==NULL)
                tmp->rc=new node();
            else
            tmp->rc->cnt+=1;
            tmp=tmp->rc;
        }
        else
        {
            if(tmp->lc==NULL)
                tmp->lc = new node();
            else
            tmp->lc->cnt+=1;
            tmp=tmp->lc;
        }
    }
    return ;
}

ll query(ll x)
{
    ll ans=0;
    node *tmp=root;
    for(ll i=31;i>=0;i--)
    {
        bool b = ((1<<i)&x);
        //if(b>1)
          //  b=1;
        if(b==0)
        {
            if(tmp->rc!=NULL&&tmp->rc->cnt > 0)
            {
                ans+=pw[i];
                tmp=tmp->rc;
            }
            else if(tmp->lc&&tmp->lc->cnt>0)
            {
                tmp=tmp->lc;
            }
            else
                {
                    ans=x;
                    break;
                }
        }
        else
            {
            if(tmp->lc!=NULL&&tmp->lc->cnt>0)
            {
                ans+=pw[i];
                tmp=tmp->lc;
            }
            else if(tmp->rc&&tmp->rc->cnt > 0)
            {
                tmp=tmp->rc;
            }
            else
                {
                    ans=x;
                    break;
                }
            }
           // cout<<ans<<" "<<i<<" "<<b<<"\n";
    }
    return ans;
}
void del(ll x)
{
    node *tmp=root;
    for(int i=31;i>=0;i--)
    {
        bool b = ((1<<i)&x);
        //if(b>0)
       //     b=1;
        if(b==1)
        {
            if(tmp->rc)
            {
                tmp->rc->cnt-=1;
                tmp=tmp->rc;
            }
            else
                break;
        }
        else
        {
            if(tmp->lc)
            {
                tmp->lc->cnt-=1;
                tmp=tmp->lc;
            }
            else
                break;
        }
    }
    return ;
}
int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int i;
    pw[0]=1;
    for(i=1;i<54;i++)
        pw[i]=(ll)2*pw[i-1];
  //  int n;
   // scanf("%d",&n);
    ll q;
    cin>>q;
    add(0);
    while(q--)
    {
        string c;
        cin>>c;
        ll x;
        cin>>x;
        if(c[0]=='+')
            add(x);
        else if(c[0]=='-')
            del(x);
        else
            cout<<(ll)query(x)<<"\n";
    }
    return 0;
}