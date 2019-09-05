#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
int r[1010];
int c[1010];
string str[1000];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>str[i];
    }
    int cnt=0;
    int rr,cc,flag=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(str[i][j]=='*')
            {
                r[i]++;
                c[j]++;
                cnt++;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int tmp=r[i]+c[j];
            if(str[i][j]=='*')
                tmp--;
            if(tmp==cnt)
            {
                flag=1;
                rr=i;
                cc=j;
                break;
            }
        }
        if(flag)
            break;
    }
    if(flag)
    {
        cout<<"YES\n";
        cout<<rr+1<<" "<<cc+1<<"\n";
    }
    else
        cout<<"NO\n";
    return 0;
}