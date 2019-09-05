#include<bits/stdc++.h>
    using namespace std;
    #define ll long long
    #define pb push_back
    int main()
    {
        int a,b;
        cin>>a>>b;
        int df=abs(a-b);
        if(df>=2||(a+b==0))
        {
            cout<<"NO\n";
        }
        else
        {
            cout<<"YES\n";
        }
        return 0;
    }