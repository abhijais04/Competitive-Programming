#include<iostream>

using namespace std;
int main()
{
     int t,s;
     long long int n;
     cin>>t;
     while(t--)
     {
         cin>>n>>s;
         if(s==0)
            cout<<"Airborne wins."<<endl;
         else
            cout<<"Pagfloyd wins."<<endl;
     }
     return 0;
}