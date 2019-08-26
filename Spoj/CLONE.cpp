#include <bits/stdc++.h>
using namespace std;
int main()
{
    while(1)
    {
        int n,ma,i;
        scanf("%d%d",&n,&ma);
        if(n==0&&ma==0)
        break;
        map <string ,int>m;
        for(i=0;i<n;i++)
        {
            string str;
            cin>>str;
            m[str]++;
        }
        int c[n+1];
        for(i=0;i<=n;i++)
        c[i]=0;
        map <string ,int>::iterator it;
        for(it=m.begin();it!=m.end();it++)
        {
            int tmp=it->second;
            c[tmp]++;
        }
        for(i=1;i<=n;i++)
        printf("%d\n",c[i]);
    }
    return 0;
}