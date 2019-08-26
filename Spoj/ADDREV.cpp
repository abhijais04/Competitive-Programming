#include <iostream>
#include<cstdio>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        long long a,b;
        scanf("%lld%lld",&a,&b);
        
    
        long long ra=0,rb=0;
        while(a!=0)
        {
            ra=(a%10)+(ra*10);
            a=a/10;
        }
         while(b!=0)
        {
            rb=(b%10)+(rb*10);
            b=b/10;
        }
        long long res=ra+rb,rr=0;
        //cout<<a<<" "<<b;
        while(res!=0)
        {
            rr=(res%10)+rr*10;
            res=res/10;
        }
        printf("%lld\n",rr);
    }
	return 0;
}