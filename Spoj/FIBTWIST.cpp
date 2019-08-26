#include <bits/stdc++.h>
using namespace std;
long long  m,n;
void mul(long long a[4][4],long long b[4][4])
{
    long long tm[4][4];
    int i,j,k;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            long long sum=0;
            for(k=0;k<4;k++)
                sum=(sum%m+(a[i][k]%m*b[k][j]%m)%m)%m;
            tm[i][j]=sum;
        }
    }
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
            a[i][j]=tm[i][j];
    }

}
long long fibb(long long k)
{
    if(k==0)
        return 0;
    k--;
    long long tmp[4][4]={{1,1,0,1},{1,0,0,0},{0,0,1,0},{0,0,1,1}};
    long long ans[4][4]={{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
  /*  for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
            cout<<tmp[i][j]<<" ";
            cout<<"\n";
    }*/
    while(k>0)
    {
        if(k%2==1)
        {
            mul(ans,tmp);
        }
        mul(tmp,tmp);
        k=k/2;
    }
    /*for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
            cout<<ans[i][j]<<" ";
            cout<<"\n";
    }*/
    //cout<<((ans[0][0]%m+ans[0][2]%m)%m);
    return ((ans[0][0]%m+ans[0][2]%m)%m+ans[0][3]%m)%m;

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        cout<<(fibb(n)+m)%m<<"\n";
    }
    return 0;
}
