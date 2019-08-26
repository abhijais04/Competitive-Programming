#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,n,b,v_a,v_b;
        scanf("%d",&a);
        n=1;
        while((n*(n+1))<2*a)
        {
            n++;
        }
        b=((n*(n+1)));
        b=b/2;
        b=b-a;
            if(n%2==0)
            {
                    v_a=n-b;
                    v_b=b+1;
            }
            else
            {
                v_a=b+1;
                v_b=n-b;
            }
        printf("TERM %d IS %d/%d\n",a,v_a,v_b);
    }
    return 0;
}
