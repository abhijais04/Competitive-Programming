#include<iostream>
using namespace std;
int main()
{
    while(1)
    {
        int n;
        cin>>n;
        if(n==-1)
            break;
        else
        {
            int a[n],i,s1=0,s2,sum=0;
            for(i=0;i<n;i++)
            {
                cin>>a[i];
                s1+=a[i];
            }
            s2=s1/n;
            if(s2*n==s1)
            {
                for(i=0;i<n;i++)
                {
                    if(a[i]<s2)
                        sum=sum+(s2-a[i]);
                }
                cout<<sum<<"\n";
            }
            else
                cout<<"-1\n";
        }
    }
    return 0;
}
