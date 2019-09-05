#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define maxn 200004
#define sqn 448
int a[maxn],cnt[1000001];
ll fans[maxn],ans;
struct node
{
    int l,r,id,block;
    node(){}
    node(int _l,int _r,int _id)
    {
        l = _l;
        r = _r;
        id = _id;
        block = _l/sqn;
    }
};
node qr[maxn];
bool cmp(node a,node b)
{
    if(a.block != b.block)
        return a.block < b.block;
    return a.r < b.r;
}
void add(int x)
{
    ans += a[x] + 2*cnt[a[x]]*a[x];
    cnt[a[x]]++;
}
void remove(int x)
{
    ans += a[x] - 2*cnt[a[x]]*a[x];
    cnt[a[x]]--;
}
int main()
{
    int n,t;
    scanf("%d %d",&n,&t);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<t;i++)
    {
        int l1,r1;
        scanf("%d%d",&l1,&r1);
        l1--;
        r1--;
        qr[i] = node(l1,r1,i);
    }
    sort(qr,qr+t,cmp);
    int cl=0,cr=-1;
    for(int i=0;i<t;i++)
    {
        while(cl < qr[i].l)
        {
            remove(cl);
            cl++;
        }
        while(cl > qr[i].l)
        {
            cl--;
            add(cl);
        }
        while(cr < qr[i].r)
        {
            cr++;
            add(cr);
        }
        while(cr > qr[i].r)
        {
            remove(cr);
            cr--;
        }
        fans[qr[i].id]=ans;
        cl = qr[i].l;
        cr = qr[i].r;
    }
    for(int i=0;i<t;i++)
        printf("%lld\n",fans[i]);
    return 0;
}