#include<bits/stdc++.h>
using namespace std;
int a[1000010];
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
    int q;
    cin>>q;
    while(q--)
    {
        string s;
        cin>>s;

        int a,b;
        cin>>a>>b;
        if(s[0]=='a')
            update(a,b);
        else
        {
            a=getval(a-1);
            b=getval(b);
            cout<<b-a<<"\n";
        }
    }
}
