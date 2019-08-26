#include <bits/stdc++.h>
using namespace std;
int main() {
    unsigned long long n,i;
    int flag=0;
    scanf("%llu",&n);
    while(1)
    {
        if(!(n&n-1))
        {
            flag=1;
            break;
        }
        else
        {
            i=n/3;
            if(!(i&i-1))
            {
                if(3*i==n)
                {flag=0;
                break;}
            }
        }
        if(n&1)
        n=(3*n)+3;
        else
        n=n/2;
    }
    if(flag==1)
    printf("TAK\n");
    else if(flag==0)
    printf("NIE\n");
	return 0;
}
