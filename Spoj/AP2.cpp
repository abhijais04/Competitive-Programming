#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long x,y,z,a0,d,l;
        scanf("%lld%lld%lld",&x,&y,&z);
            d=(y-x)/(((2*z)/(x+y))-5);
            //cout<<d<<"\n";
            a0=x-(2*d);
            if(d!=0)
            l=((y-a0)/d)+3;
            else if(d==0)
                l=z/a0;
            printf("%lld\n",l);
            for(int i=0;i<l;i++)
            {
                printf("%lld ",(a0+(i*d)));
            }
            printf("\n");
    }
    return 0;
}
