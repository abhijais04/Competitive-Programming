#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    set <int>s;
    int f=n;
    while(n--)
    {
        int id,nf;
        scanf("%d%d",&id,&nf);
        s.insert(id);
        while(nf--)
        {
            int tmp;
            scanf("%d",&tmp);
            s.insert(tmp);
        }
    }
    int ans=s.size()-f;
    printf("%d\n",ans);
    return 0;
}
