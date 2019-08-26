#include <bits/stdc++.h>
using namespace std;
bool ans[1001001];
int sum[1000010],v[1001010];
int main()
{
    int x,k,i;
    cin>>x>>k;
    for(i=0;i<k;i++)
    {
        cin>>v[i];
    }
    sum[0]=v[0];
   // cout<<sum[0]<<" "<<;
    for(i=1;i<k;i++)
    {
        sum[i]=sum[i-1]+v[i];
     //   cout<<sum[i]<<" ";
    }
    for(i=1;i<=x;i++)
        ans[i]=false;
    ans[0]=true;
    for(i=0;i<k;i++)
    {
        for(int j = sum[i];j<=x;j++)
        {
         //   if(j==13)
       //         cout<<"asd\n"<<" "<<sum[i]<<"\n";
            ans[j]|=ans[j-sum[i]];
        }
    }
    if(ans[x]==true)
        cout<<"YES\n";
    else
        cout<<"NO\n";
}
