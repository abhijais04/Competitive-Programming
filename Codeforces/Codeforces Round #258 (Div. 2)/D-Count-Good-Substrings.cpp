#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sc(x) scanf("%lld",&x)
ll zero[2];
ll one[2];
int main()
{
    string str;
    cin>>str;
    int l = str.length();
    ll odd=0,even=0;
    for(int i=0;i<l;i++)
    {
        int val = str[i]-'a';
        int id = i%2;
        if(val==0)
        {
            zero[id]++;
            odd += zero[id];
            even += zero[id^1];

        }
        else
        {
            one[id]++;
            odd += one[id];
            even += one[id^1];
        }
    }

    cout<<even<<" "<<odd<<"\n";
    return 0;

}