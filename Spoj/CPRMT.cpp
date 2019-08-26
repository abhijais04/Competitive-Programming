#include <bits/stdc++.h>
using namespace std;
int main()
{
     char a[2010],b[2010];
     while(scanf("%s",&a)!=EOF)
     {
         scanf("%s",&b);
         int l1=strlen(a),l2=strlen(b),i,j;
         int ac[28],bc[28];
         for(i=0;i<28;i++)
         {
             ac[i]=bc[i]=0;
         }
         for(i=0;i<l1;i++)
         {
             ac[a[i]-'a']++;
         }

         for(i=0;i<l2;i++)
         {
             bc[b[i]-'a']++;
         }
         for(i=0;i<26;i++)
         {
             int tmp=min(ac[i],bc[i]);
             for(j=0;j<tmp;j++)
                cout<<(char)('a'+i);
         }
         cout<<"\n";
     }
     return 0;
}
