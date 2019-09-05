#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int cnt=0;
    while(n)
    {
        n=n-(n&(-n));
        cnt++;
    }
    cout<<cnt;
}