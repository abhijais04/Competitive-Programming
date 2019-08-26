#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool ar[1000013];
int pos[1000012];
int main()
{
    int i;
    vector <int>v;
    for(i=2;i*i*i<=1000010;i++)
    {
        v.push_back(i*i*i);
    }
    for(i=0;i<v.size();i++)
    {
        for(int j=v[i];j<=1000010;j+=v[i])
            ar[j]=1;
    }
    int cnt=0;
    for(i=1;i<=1000010;i++)
    {
        if(!ar[i])
        {
           // cout<<"asd "<<i<<"\n";
            cnt++;
            pos[i]=cnt;
          //  if(i<100)
            //    cout<<i<<" "<<pos[i]<<"\n";
        }
    }
    int t;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        int n;
        cin>>n;
        cout<<"Case "<<i<<": ";
        if(ar[n])
        {
            cout<<"Not Cube Free\n";
        }
        else
            cout<<pos[n]<<"\n";
    }
    return 0;
}
