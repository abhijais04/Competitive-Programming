#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
int a[100100];
int b[100010];
int main()
{
    int l;
    cin>>l;
    string str;
    int p;

    cin>>p;
    cin>>str;

    p--;
    int b=-1,e=-1;
    int sum=0;
    if(p>=l/2)
    {
        p=l-1-p;
    }
    for(int i=0;i<l/2;i++)
    {

        a[i]=0;
        int pp=l-1-i;
        a[i]=min(abs((int)str[i]-str[pp]),26-abs((int)str[i]-str[pp]));
        if(a[i]!=0)
        {
            if(i>p)
            {
                e=i;
            }
            else if(i<p)
            {
                if(b==-1)
                    b=i;
            }
        }
        a[l-1-i]=a[i];
            sum+=a[i];
    }
    int ans=sum;
    //cout<<ans<<"\n";
    if(b!=-1||e!=-1)
    {
        if(b==-1)
        {
            ans+=(e-p);
        }
        else if(e==-1)
        {
            ans+=(p-b);
        }
        else
        {
            ans+=min(2*(e-p)+(p-b),2*(p-b)+(e-p));
        }
    }

    cout<<ans<<"\n";
}