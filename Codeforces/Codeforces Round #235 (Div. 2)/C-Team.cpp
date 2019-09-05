#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
int main()
{
    int n,m;
    cin>>n>>m;
    string ans="";
    if((n+1)*2<m||m+1<n)
    {
        cout<<"-1\n";
        return 0;
    }

    while(n>0&&m>0)
    {
        if(n+1>=m)
        {
            if(n>0)
            ans+="10";
            m--;
            n--;
        }
        else
        {
            if(m>=2)
            ans+="110";
            else
            {
                ans+="10";
                m++;
            }
            n--;
            m-=2;
        }
    }
    if(m==0&&n)
    {
        if(n==1)
        {
            ans="0"+ans;
        }
        else
        {
            cout<<"-1\n";
            return 0;
        }
    }
    else if(n==0&&m)
    {
        if(m==2)
            ans+="11";
        else if(m==1)
            ans+="1";
        else{
            cout<<"-1\n";
            return 0;
        }
    }
    cout<<ans<<"\n";
}