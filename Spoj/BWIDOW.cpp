#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[500];
ll dp[3][1000];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int in[n],ou[n],i,mni;
        int mx=-1;
        for(i=0;i<n;i++)
        {
            cin>>in[i];
            {
                if(in[i]>mx)
                {
                    mni=i;
                    mx=in[i];
                }
                else if(in[i]==mx)
                {
                    if(ou[i]<ou[mni])
                    {
                        mni=mni;
                    }
                    else
                    mni=i;
                }
            }
            cin>>ou[i];
        }
        int flag=1;
        for(i=0;i<n;i++)
        {
            if(i!=mni)
            {
                if(ou[i]>=mx)
                {
                    flag=0;
                    break;
                }
            }
        }
        if(flag)
            cout<<mni+1<<"\n";
        else
            cout<<"-1\n";

    }
    return 0;
}
