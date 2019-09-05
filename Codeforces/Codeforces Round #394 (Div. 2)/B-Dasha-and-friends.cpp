#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int main()
{
    int n,l;
    cin>>n>>l;
    int a[n],b[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>b[i];
    for(int i=0;i<l;i++)
    {
        int tmp[n];
        for(int j=0;j<n;j++)
        {
            tmp[j]=b[j]-i;
            if(tmp[j]<0)
                tmp[j]+=l;
        }
        sort(tmp,tmp+n);
        int flag=1;
        for(int j=0;j<n;j++)
        {
            if(tmp[j]!=a[j])
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
        {
            cout<<"YES\n";
            return 0;
        }
    }
    cout<<"NO\n";
}