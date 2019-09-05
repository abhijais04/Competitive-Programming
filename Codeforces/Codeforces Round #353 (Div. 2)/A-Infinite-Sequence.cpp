#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int flag=0;
    if(c==0)
    {
        if(a==b)
            flag=1;
    }
    else
    {
        if(((b-a)%c==0&&(b-a)/c>0)||(b==a))
            flag=1;
    }
    if(flag==1)
        cout<<"YES\n";
    else
        cout<<"NO\n";

}