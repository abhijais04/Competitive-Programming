#include <bits/stdc++.h>
using namespace std;
#define ll long long
string a;
ll fn(int i,int cur,int pre)
{
    //cout<<i<<" "<<cur<<" "<<pre<<"\n";
    if(i<0)
        return 0;
    if(i==0)
    {
        int r=0;
        if(a[0]-'0'<=cur)
            r++;
        if(a[0]+cur-'0'<=pre)
            r++;
    //    cout<<i<<" "<<r<<"\n";
        return r;
    }
    int tmp=0;
    if(cur+a[i]-'0'<=pre)
    {
        tmp+=fn(i-1,a[i]+cur-'0',pre);
    }
    if(a[i]-'0'<=cur)
    {
        tmp+=fn(i-1,a[i]-'0',cur);
    }
    //cout<<i<<" "<<tmp<<"\n";
    return tmp;
}
int main()
{
    int t=1;
    while(1)
    {
        cin>>a;
        if(a[0]=='b')
            break;
        else
        {
            cout<<t++<<". ";
            if(a.length()>1)
            cout<<fn(a.length()-2,a[a.length()-1]-'0',10000000);
            else
                cout<<"1";
            cout<<"\n";
        }
    }
}
