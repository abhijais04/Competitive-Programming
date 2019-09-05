#include <bits/stdc++.h>
using namespace std;
int cnt[110];
int main()
{
    int t[5],sum=0,i;
    for(i=0;i<5;i++)
    {
        cin>>t[i];
        cnt[t[i]]++;
        sum+=t[i];
    }
    int mx=0;
    for(i=0;i<107;i++)
    {
        if(cnt[i]>=3)
        {
            if(i*3>mx)
                mx=i*3;
        }
        else if(cnt[i]>=2)
        {
            if(i*2>=mx)
                mx=i*2;
        }
    }
    cout<<sum-mx<<"\n";
    return 0;
}