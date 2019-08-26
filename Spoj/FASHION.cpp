#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n],b[n],i;
        for(i=0;i<n;i++)
            cin>>a[i];
        for(i=0;i<n;i++)
            cin>>b[i];
            sort(a,a+n);
            sort(b,b+n);
        long sum=0;
        for(i=0;i<n;i++)
        {

            sum=sum+(a[i]*b[i]);
        }
        cout<<sum<<"\n";
    }
    return 0;
}
