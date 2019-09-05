#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    double a,b;
    cin>>a>>b;
    int n;
    cin>>n;
    double mn = 10000000;
    while(n--)
    {
        double x,y,v;
        cin>>x>>y>>v;
        double tmp=((x-a)*(x-a))+((y-b)*(y-b));
        double d1 = (double)sqrt(tmp);
        //double d2 = (double)sqrt(((x-a)*(x-a))+((y-b)(y-b)));
        d1 = (double)(d1/(double)v);
        if(d1<mn)
            mn=d1;
    }
    cout<<setprecision(16)<<mn<<"\n";
}