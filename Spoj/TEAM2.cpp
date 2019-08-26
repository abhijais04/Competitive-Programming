#include <bits/stdc++.h>
using namespace std;
int main()
{
    //sieve();
    {
        long long a[4];
        int cnt=1;
        while(cin>>a[0]>>a[1]>>a[2]>>a[3])
        {
            sort(a,a+4);
            cout<<"Case "<<cnt++<<": ";
            cout<<a[3]+a[2]<<"\n";
        }
    }
            return 0;
}
