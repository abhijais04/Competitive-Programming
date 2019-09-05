#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    while(b)
    {
        int tmp=a%b;
        a=b;
        b=tmp;
    }
    return a;
}
int main()
{
    int n,i;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    //cout<<a[0]<<" ";
    vector <int >v;
    v.push_back(a[0]);
    for(i=1;i<n;i++)
    {
        if(gcd(a[i],v[v.size()-1])!=1)
            v.push_back(1);
        v.push_back(a[i]);
    }
    cout<<v.size()-n<<"\n";
    for(i=0;i<v.size();i++)
        cout<<v[i]<<" ";
}