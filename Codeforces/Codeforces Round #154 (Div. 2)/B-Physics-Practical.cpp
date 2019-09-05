#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
ll a[100010];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    cin>>a[i];
    sort(a,a+n);
    /*cout<<"\n";


    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<"\n";*/
    int ans=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(i>ans)
            break;
        if(a[i]*2>=a[n-1])
            {
                ans=min(ans,i);
                continue;
            }
        int x=2*a[i];
        int idx=lower_bound(a,a+n,x)-a;
        int cnt=0;
        if(idx==n)
        {
            idx--;
        }
        else
        {
            if(a[idx]>2*a[i])
                idx--;
            else
            {
                idx=upper_bound(a,a+n,x)-a;
                idx--;
            }

        }
        if(idx<i)
            continue;
        ans=min(ans,i+(n-1-idx));
    }
    if(n==1)
        ans=0;
    cout<<ans<<"\n";
    return 0;
}