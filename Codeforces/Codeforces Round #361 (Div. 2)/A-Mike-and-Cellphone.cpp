#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int main()
{
    map <int , pair<int,int> >mp;

    mp[1]={0,0};
    mp[2]={0,1};
    mp[3]={0,2};
    mp[4]={1,0};
    mp[5]={1,1};
    mp[6]={1,2};
    mp[7]={2,0};
    mp[8]={2,1};
    mp[9]={2,2};
    mp[0]={3,1};
    int ar[4][3]={{1,2,3},{4,5,6},{7,8,9},{-1,0,-1}};
    int n;
    cin>>n;
    string str;
    cin>>str;
    int x[n-1],y[n-1],i,j,k;
    int flag=0;
    int t1 = mp[(int)(str[0]-'0')].first;
    int t2 = mp[(int)(str[0]-'0')].second;
    int a=t1,b=t2;
    for(i=1;i<n;i++)
    {
        int tx = mp[(int)(str[i]-'0')].first;
        int ty = mp[(int)(str[i]-'0')].second;

        x[i-1] = tx-t1;
        y[i-1] = ty-t2;
        t1=tx;
        t2=ty;
    }

    for(i=0;i<4;i++)
    {
        for(j=0;j<3;j++)
        {
            if(i!=a||b!=j)
            {
                int valid = 1;
            int xx = i,xy = j;
            for(k=0;k<n-1;k++)
            {
                if(xx>=4||xy>=3||ar[xx][xy]<0||xx<0||xy<0)
                {
                    valid = 0;
                    break;
                }
                xx+=x[k];
                xy+=y[k];
               // cout<<xx<<" "<<xy<<"\n";
                if(xx>=4||xy>=3||ar[xx][xy]<0||xx<0||xy<0)
                {
                    valid = 0;
                    break;
                }
            }
            if(valid ==1)
            {
                flag=1;
                break;
            }
            }
          //  cout<<"asd\n";
        }
        if(flag==1)
            break;
    }
    if(flag==1)
        cout<<"NO\n";
    else
        cout<<"YES\n";
}