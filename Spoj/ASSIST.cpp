#include<bits/stdc++.h>
#define pb push_back
using namespace std;
vector<int >v;
bool pr[1000100];
int n=100100;
void sieve()
{
    int i,j;
    for(i=2;v.size()<=3001;i++)
    {
        if(pr[i]==0)
        {
            int cnt=0;
            v.pb(i);
          //  cout<<i<<" ";
            for(j=i+1;j<=n;j++)
            {
                if(pr[j]==0)
                {
                if(cnt==i-1)
                    {
                    pr[j]=1;
                    cnt=0;
                    }
                else
                    cnt++;
                }
            }
        }
    }
}
int main()
{
    sieve();
    while(1)
    {
        int a;
        cin>>a;
        if(a==0)
            break;
        cout<<v[a-1]<<"\n";
    }
}
