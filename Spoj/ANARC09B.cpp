#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b)
{
    while(b)
    {
        long long tmp=a%b;
        a=b;
        b = tmp;
    }
    return a;
}
int main()
{
    //int t;
    //scanf("%d",&t);
    while(1)
    {
        long long a,b,c,d;
        cin>>a>>b;
        if(a==0||b==0)
            break;
        c = gcd(a,b);
        a = a/c;
        b = b/c;
        d = a*b;
        cout<<d<<"\n";
    }
    return 0;
}
