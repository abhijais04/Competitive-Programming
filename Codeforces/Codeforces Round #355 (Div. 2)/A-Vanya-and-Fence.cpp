#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int main()
{
    int n,h;
    cin>>n>>h;
    int a[n],cnt=0;
    for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]<=h)
                cnt++;
            else if(a[i]>h)
                cnt+=2;
        }
        cout<<cnt<<"\n";
    return 0;
}