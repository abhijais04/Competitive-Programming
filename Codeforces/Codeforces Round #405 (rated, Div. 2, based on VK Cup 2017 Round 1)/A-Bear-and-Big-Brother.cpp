#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sc(x) scanf("%d",&x)

int main()
{
    int a,b;
    cin>>a>>b;
    int cnt=0;
    while(a<=b)
    {
        a*=3;
        b*=2;
        cnt++;
    }
    cout<<cnt<<"\n";
    return 0;
}