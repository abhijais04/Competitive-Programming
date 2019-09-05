#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

int main()
{
    int s1,m;
    cin>>m>>s1;
    int a[m],b[m];
    int s=s1;
    for(int i=0;i<m;i++)
        a[i]=0,b[i]=0;
    if(m==1&&s1==0)
    {
        cout<<"0 0\n";
        return 0;
    }
    a[0]=1;
    s--;
    for(int i=m-1;i>=0;i--)
    {
        if(s>0)
        {
            int tmp=min(9-a[i],s);
            s=s-(tmp);
            a[i]+=tmp;
        }
        else
            break;
    }
    if(s!=0)
    {
        cout<<"-1 -1\n";
        return 0;
    }
    s=s1;
    b[0]=min(9,s);
    s=s-b[0];
    for(int i=1;i<m;i++)
    {
        if(s>0)
        {
            int tmp = min(s,9);
            s-=tmp;
            b[i]=tmp;
        }
        else
            break;
    }
    int sm1=0,sm2=0;
    for(int i=0;i<m;i++)
    {
        sm1+=a[i];
        sm2+=b[i];
    }
    if(s!=0||sm1!=s1||sm2!=s1)
    {
        cout<<"-1 -1\n";
        return 0;
    }
    for(int i=0;i<m;i++)
        cout<<a[i];
    cout<<" ";
    for(int i=0;i<m;i++)
        cout<<b[i];
    cout<<"\n";
    return 0;
}