#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n,mx,c=0;
        cin>>n>>mx;
        int a[n+1];
        int i;
        int s[n+1];
        s[0]=0;
        for(i=1;i<=n;i++)
        {
            cin>>a[i];
            s[i]=s[i-1]+a[i];
        }
        int l=1,r=1,ans=0;
        while(r<=n&&l<=r)
        {
            while(r<=n&&s[r]-s[l-1]<=mx)
            r++;
            if(r-l>=1)
            r--;
                if(s[r]-s[l-1]<=mx)
                {
                    if(r-l+1>c)
                      {
                            c=r-l+1;
                            ans=s[r]-s[l-1];
                      }
                    else if(c==r-l+1)
                    {
                        ans=min(ans,s[r]-s[l-1]);
                    }
                }
            l++;
            if(r<l)
                r++;
        }
        cout<<ans<<" "<<c<<"\n";
    }
    return 0;
}
