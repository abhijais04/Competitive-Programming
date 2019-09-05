#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
string str;
int main()
{
    int n,a,b;
    cin>>n>>a>>b;
    a--;
    b--;
    //string str;
    cin>>str;
    if(str[a]==str[b])
    {
        cout<<"0\n";
        return 0;
    }
    else
    {
        cout<<"1\n";
    }
    return 0;
}