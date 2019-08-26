#include <bits/stdc++.h>
using namespace std;
void show(int n)
{
    if(n==0)
        return ;
    if(n>0)
    {

        if(n%2==1)
        {
            show(-(n/2));
             printf("1");
        }
        else
        {
            show(-n/2);
             printf("0");
        }
    }
    else
    {
        if(n%2==-1)
        {
            show(-(n/2)+1);
            printf("1");
        }
        else
        {

            show(-(n/2));
            printf("0");
        }
    }

}
int main()
{
    //int t;
   // scanf("%d",&t);
    //while(t--)
    {
        int n;
        scanf("%d",&n);
        if(n==0)
            printf("0");
        else
            show(n);
        printf("\n");
    }
    return 0;
}
