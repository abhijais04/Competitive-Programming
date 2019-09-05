#include <bits/stdc++.h>
using namespace std;
int pr[1010];
int main()
{
    int i,j;
    for(i=2;i*i<=110;i++)
    {
        if(pr[i]==0)
        {
            for(j=2*i;j<=110;j+=i)
                pr[j]=1;
        }
    }
    vector <int>v;
    for(i=2;i<=100;i++)
    {
        if(pr[i]==0)
        {
            v.push_back(i);
        }
    }
    int q=0;
    int cnt=0;
    i=0,j=0;
    for(i=2;i<=64;i*=2)
    {
        cout<<i<<"\n";
        fflush(stdout);
        string tr;
        cin>>tr;
        if(tr[0]=='y')
            cnt++;
        else
        {
            break;
        }
    if(cnt>1)
        {
            cout<<"composite\n";
            return 0;
        }
    }

    for(i=3;i<=81;i*=3)
    {
        cout<<i<<"\n";
        fflush(stdout);
        string tr;
        cin>>tr;
        if(tr[0]=='y')
            cnt++;
        else
        {
            break;
        }
        if(cnt>1)
        {
            cout<<"composite\n";
            return 0;
        }
    }
    for(i=5;i<=25;i*=5)
    {
        cout<<i<<"\n";
        fflush(stdout);
        string tr;
        cin>>tr;
        if(tr[0]=='y')
            cnt++;
        else
        {
            break;
        }
        if(cnt>1)
        {
            cout<<"composite\n";
            return 0;
        }
    }
    for(i=7;i<=49;i*=7)
    {
        cout<<i<<"\n";
        fflush(stdout);
        string tr;
        cin>>tr;
        if(tr[0]=='y')
            cnt++;
        else
        {
            break;
        }
        if(cnt>1)
        {
            cout<<"composite\n";
            return 0;
        }
    }

    for(i=11;i<=100;i*=11)
    {
        cout<<i<<"\n";
        fflush(stdout);
        string tr;
        cin>>tr;
        if(tr[0]=='y')
            cnt++;
        else
        {
            break;
        }
        if(cnt>1)
        {
            cout<<"composite\n";
            return 0;
        }
    }
     i=0;
     while(v[i]<13)
        i++;
     for(i;v[i]<=47;i++)
     {
         cout<<v[i]<<"\n";
         fflush(stdout);
         string tr;
         cin>>tr;
         if(tr[0]=='y')
            cnt++;
         if(cnt>1)
         {
             cout<<"composite\n";
             return 0;
         }
     }
     if(cnt<=1)
        cout<<"prime\n";
     else
        cout<<"composite\n";
     return 0;
}