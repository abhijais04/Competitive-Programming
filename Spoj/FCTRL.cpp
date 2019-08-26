#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,s=0;
        scanf("%d",&n);
        while(n)
        {
            s=s+(n/5);
            n=n/5;
        }
        printf("%d\n",s);
    }
    return 0;
}
