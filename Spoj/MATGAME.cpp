#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int i,a[n][m],j,gr[n][m];
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        int ans=0;
        for(i=0;i<n;i++)
        {
            gr[i][m-1]=a[i][m-1];
            for(j=m-2;j>=0;j--)
            {
                if(a[i][j]<=gr[i][j+1])
                    gr[i][j]=a[i][j]-1;
                else
                    gr[i][j]=a[i][j];
            }
        }
        for(i=0;i<n;i++)
        {
            ans=ans^gr[i][0];
        }
        if(ans==0)
        {
            cout<<"SECOND\n";
        }
        else
            cout<<"FIRST\n";
    }
    return 0;
}
