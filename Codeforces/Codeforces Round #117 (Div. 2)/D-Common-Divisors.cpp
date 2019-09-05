#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
bool check(string s,string ss)
{
    int l1=s.length();
    int l2=ss.length();
    string tt=s;
    for(int i=1;i<l2/l1;i++)
    {
        {
            s+=tt;
        }
    }
    return (s==ss);
}
int main()
{
    string s1,s2;
    cin>>s1;
    cin>>s2;
    int ans=0;
    int l1=s1.length(),l2=s2.length();
    if(l1>l2)
    {
        string tmp=s1;
        s1=s2;
        s2=tmp;
        l1=s1.length();
        l2=s2.length();
    }
    int gcd=__gcd(l1,l2);
    vector<int> dv;
    string t1="",t2="";
    for(int i=0;i<gcd;i++)
    {
        t1+=s1[i];
        t2+=s2[i];
    }
    if(check(t1,s1)==false||check(t2,s2)==false||t1!=t2)
    {
        cout<<"0\n";
        return 0;
    }
    for(int i=1;i*i<=gcd;i++)
    {
        if(gcd%i==0)
        {
            dv.pb(i);
            if(i*i!=gcd)
                dv.pb(gcd/i);
        }
    }
    sort(dv.begin(),dv.end());
    //cout<<t1<<"\n"<<t2<<"\n";
    for(int i=0;i<dv.size();i++)
    {
        int tmp=dv[i];
        string cc="";
        for(int j=0;j<tmp;j++)
        {
            cc+=s1[j];
        }
        string tt=cc;
        for(int j=1;j<gcd/tmp;j++)
            cc+=tt;
        //cout<<cc<<"\n";
        if(cc==t1)
        {
            ans++;
        }
    }
    cout<<ans<<"\n";
    return 0;
}