#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d,n,i;
    cin>>n>>a>>b>>c>>d;
    long long cnt=0;
    for(i=1;i<=n;i++)
    {
        int x=i,y,z,m,nn;
        y=x+(b-c);
        m=a+b+x-d-c;
        nn=x+a-d;
        if(y<=n&&m<=n&&nn<=n&&y>0&&nn>0&&m>0)
        {
            cnt+=(n);
        }
    }
    cout<<cnt<<"\n";
}