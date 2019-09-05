#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
int main()
{
    //while(1)
    {
        int n,m;
        cin>>n>>m;
    if(n-m>m-1)
        cout<<min(n,m+1)<<"\n";
    else
        cout<<max(1,m-1)<<"\n";
    }
}