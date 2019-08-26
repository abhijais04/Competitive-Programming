#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        if(y==x||y+2==x)
        {
            if(y%2==0)
                cout<<x+y<<"\n";
            else
                cout<<x+y-1<<"\n";
        }
        else
            cout<<"No Number\n";
    }
    return 0;
}
