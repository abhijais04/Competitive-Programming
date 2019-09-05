#include <bits/stdc++.h>
    using namespace std;
    int main()
    {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        int n;
        int i;
        cin>>n;
        int ar[n+1];
        vector <int>v;
        v.push_back(-10);
        for(i=0;i<n;i++)
        {
            int a;
            cin>>a;
            v.push_back(a);
        }
        sort(v.begin(),v.end());
        if(n&1)
        {
            ar[1]=v[1];
                    for(i=2;i<=n;i++)
                    {
                    if(i&1)
                    ar[i]=v[i-1];
                    else
                    ar[i]=v[i+1];
                }
        }
        else
        {
            ar[1]=v[1];
            for(i=2;i<n;i++)
            {
                if(i&1)
                ar[i]=v[i-1];
                else
                ar[i]=v[i+1];

            }
            ar[n]=v[n];
        }
        int f=1;
        for(i=2;i<=n;i++)
        {
            if(((i&1)&&ar[i]>ar[i-1])||((i%2==0)&&(ar[i]<ar[i-1])))
            {
                f=0;
                break;
            }
        }
        if(f)
        {
            for(i=1;i<=n;i++)
                cout<<ar[i]<<" ";
        }
        else
            cout<<"Impossible";
        return 0;
    }