#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int main()
{
    int n;
    cin>>n;
    int n1=n;
    int cnt=0;
    int mx=0;
    vector<int> v;
    while(n1)
    {
        cnt++;
        int tmp=n1%10;
        v.push_back(tmp);
        mx=max(mx,tmp);
        n1/=10;
    }
    for(int i=0;i<v.size()/2;i++)
    {
        int tmp = v[i];
        v[i]=v[v.size()-1-i];
        v[v.size()-1-i]=tmp;
    }
    cout<<mx<<"\n";
    for(int i=0;i<mx;i++)
    {
        string ans="";
        for(int j=0;j<v.size();j++)
        {
            if(v[j]==0)
            {
                if(ans.length()>0)
                    ans=ans+"0";
            }
            else
            {
                ans+="1";
                v[j]--;
            }
        }
        cout<<ans<<" ";
    }

    return 0;
}