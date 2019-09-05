#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int main()
{
    int n;
    cin>>n;
    string sa,sb;
    cin>>sa>>sb;
    vector<int> a,b;
    vector<int> vs(10,0),vs2;
    for(int i=0;i<n;i++)
    {
        a.pb(sa[i]-'0');
        b.pb(sb[i]-'0');
        vs[b[i]]++;
    }
    int aa=0,bb=0,idx=0;
    vs2=vs;
    for(int i=0;i<n;i++)
    {
        int x=a[i];
        int f=0;
        for(int j=x;j<=9;j++)
        {
            if(vs[j]>0)
            {
                f=1;
                vs[j]--;
                break;
            }
        }
        if(f==0)
            aa++;
        f=0;
        for(int j=x+1;j<=9;j++)
        {
            if(vs2[j]>0)
            {
                f=1;
                vs2[j]--;
                break;
            }
        }
        if(f==1)
            bb++;
    }
    cout<<aa<<"\n"<<bb<<"\n";
    return 0;
}