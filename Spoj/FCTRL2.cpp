#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int arr[200];
        int n,m,c=0,i,j,temp;
        cin>>n;
        arr[0]=1;
        m=1;
        for(i=2;i<=n;i++)
        {
            c=0;
            for(j=0;j<m;j++)
            {
                temp=arr[j]*i;
                arr[j]=(temp+c)%10;
                c=(temp+c)/10;
            }
            while(c!=0)
            {
                arr[m]=c%10;
                c=c/10;
                m++;
            }
        }
        for(i=m-1;i>=0;i--)
            cout<<arr[i];
        cout<<"\n";
    }
    return 0;
}