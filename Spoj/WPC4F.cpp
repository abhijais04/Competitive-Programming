#include <bits/stdc++.h>
using namespace std;
int c[25][5];
int fn(int a,int p,int n)
{
    if(a>n-1)
        return 0;
    else
    {
        if(p==0)
        {
            return min(fn(a+1,1,n)+c[a][1],fn(a+1,2,n)+c[a][2]);
        }
        else if(p==1)
        {
            return min(fn(a+1,0,n)+c[a][0],fn(a+1,2,n)+c[a][2]);
        }
        else
            return min(fn(a+1,1,n)+c[a][1],fn(a+1,0,n)+c[a][0]);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        int n,i;
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>c[i][0]>>c[i][1]>>c[i][2];
        }
        int a,b,c1;
        a=fn(1,0,n)+c[0][0];
        b=fn(1,1,n)+c[0][1];
        c1=fn(1,2,n)+c[0][2];
        cout<<min(a,min(b,c1))<<"\n";
    }
    return 0;
}
