#include<bits/stdc++.h>
using namespace std;
int a[1010];
void solve()
{
    int n,k;
    cin>>n>>k;
    for(int j=0;j<n;j++)
        cin>>a[j];
    int rem=0,hv=0,i;
    for(i=0;i<n && hv < k;i++)
    {
        if(a[i]>=8)
        {
                hv+=8;
                rem+=(a[i]-8);
        }
        else
        {
            hv += min(8,rem+a[i]);
            rem = max(0,rem-(8-a[i]));
        }
        if(hv >= k)
            break;
    }
    if(hv < k)
        cout<<"-1\n";
    else
        cout<<i+1<<"\n";
}
int main()
{

        solve();
    return 0;
}