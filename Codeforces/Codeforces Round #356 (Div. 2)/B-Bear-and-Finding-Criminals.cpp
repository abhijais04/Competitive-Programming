#include <bits/stdc++.h>
using namespace std;
int cnt[110];
int main()
{
    int n,a;
    cin>>n>>a;
    int d[n];
    for(int i=1;i<=n;i++)
        cin>>d[i];
    int cnt=0;
    if(d[a]==1)
    cnt++;
    int i = a-1,j=a+1;
    while(i>0||j<=n)
    {
        int f1=0,f2=0;
        if(i>0)
        {
            if(j<=n)
            {
                if(d[i]>0&&d[j]>0)
                    cnt+=2;
            }
            else
            {
                if(d[i]>0)
                    cnt++;
            }
        }
        else
        {
            if(j<=n)
            {
                if(d[j]>0)
                    cnt++;
            }
        }
        i--;
        j++;
    }
    cout<<cnt<<"\n";
}