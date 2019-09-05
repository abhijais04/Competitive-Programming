#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n,i;
    cin>>n;
    int flag=0;
    for(i=0;i<n;i++)
    {
        string str;
        int a,b;
        cin>>str;
        cin>>a>>b;
        if(a>=2400&&(b-a)>0)
            flag=1;
    }
    if(flag==1)
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}