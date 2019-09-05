#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
int main()
{
    int r=0,b=0,y=0,g=0;
    string str;
    cin>>str;
    int n=str.length();
    for(int i=0;i<n;i++)
    {
        //cout<<str[i]<<"\n";
        if(str[i]=='R')
            r=i%4;
        else if(str[i]=='B')
            {
                b=i%4;
            }
        else if(str[i]=='Y')
            {
                y=i%4;
            }
        else if(str[i]=='G')
            {
                g=i%4;
            }
    }
    //cout<<r<<" "<<b<<" "<<g<<" "<<y<<"\n";
    int ar=0,ab=0,ay=0,ag=0;
    for(int i=r;i<n;i+=4)
    {
        if(str[i]=='!')
            ar++;
    }
    for(int i=b;i<n;i+=4)
    {
        if(str[i]=='!')
            ab++;
    }
    for(int i=y;i<n;i+=4)
    {
        if(str[i]=='!')
            ay++;
    }
    for(int i=g;i<n;i+=4)
    {
        if(str[i]=='!')
            ag++;
    }
    cout<<ar<<" "<<ab<<" "<<ay<<" "<<ag<<"\n";
    return 0;
}