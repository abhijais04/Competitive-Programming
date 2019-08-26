#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    ll cnt=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        cout<<"Case "<<cnt++<<": ";
        if(n==3)
        {
        	cout<<"2 3\n";
        }
        else
       	{
       	if(n%2==1)
            n--;
        cout<<(n/2)<<" "<<n<<"\n";
       	}
    }
    return 0;
}
