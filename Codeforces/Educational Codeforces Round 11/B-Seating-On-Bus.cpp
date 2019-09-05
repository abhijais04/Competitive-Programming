#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,m;
    cin>>n>>m;
    int st=2*n+1;
    int st1=1;
    int cnt=0;
    if(m<=2*n)
    {
        for(i=1;i<=m;i++)
            cout<<i<<" ";
    }
    else
    {
        while(cnt<m)
        {
            if(st<=m&&cnt<m)
            {
                cout<<st<<" ";
                cnt++;
                st++;
            }
            if(st1<=2*n&&cnt<m)
            {
                cout<<st1<<" ";
                st1++;
                cnt++;
            }
            if(st<=m&&cnt<m)
            {
                cout<<st<<" ";
                cnt++;
                st++;
            }
            if(st1<=2*n&&cnt<m)
            {
                cout<<st1<<" ";
                st1++;
                cnt++;
            }
        }
    }
    return 0;
}