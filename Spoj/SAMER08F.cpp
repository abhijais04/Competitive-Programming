#include <iostream>
using namespace std;

int main() {
	
	while(1)
	{
		int n;
		cin>>n;
		if(n==0)
		break;
		else
		{
			n=n*(n+1)*(n+n+1)/6;
			cout<<n<<"\n";
		}
	}
	return 0;
}