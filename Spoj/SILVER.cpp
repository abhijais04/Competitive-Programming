#include <bits/stdc++.h>
using namespace std;
int main()
{
    while(1)
    {
        int n;
        scanf("%d",&n);
        if(n==0)
            break;
        else
        {
            int i=1;
            while((1<<i)-1<n)
                i++;
            i--;
            printf("%d\n",i);
        }
    }
    return 0;
}
