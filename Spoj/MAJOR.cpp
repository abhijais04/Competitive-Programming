#include <bits/stdc++.h>
using namespace std;
//long long a[1000010];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        map <int ,int >m;
        int tn=n;
        while(n--)
        {
            int a;
            scanf("%d",&a);
            m[a]+=1;
        }
        map <int ,int >::iterator it;
        int mx=0,val;
        for(it=m.begin();it!=m.end();it++)
            if(it->second>mx)
               {
                    mx=it->second;
                    val=it->first;
               }
        if(mx>tn/2)
        {
            printf("YES %d\n",val);
        }
        else
            printf("NO\n");
        printf("\n");
    }
    return 0;
}
