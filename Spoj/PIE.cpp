#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
   while(t--)
   {
    int n,f,i;
   scanf("%d%d",&n,&f);
    long double v[n+1],mx=0;
   for(i=1;i<=n;i++)
   {
       long double tmp;
       scanf("%Lf",&tmp);
       v[i]=tmp*tmp*3.14159265358979323846264338327950;
       if(mx<v[i])
       mx=v[i];
   //    sum+=v[i];
   }
   int c;
  long double low=0,high=mx,mid;
   while(high-low>1e-6)
   {
      c=0;
    //cout<<"low high "<<low<<" "<<high<<" ";
    mid=(low+high)/2.0;
    for(i=1;i<=n;i++)
    {
        c+=(int)(v[i]/mid);
    }
    //cout<<"c "<<c<<"\n";
    if(c>=f+1)
    low=mid;
    else
    high=mid;
   }
   printf("%.4Lf\n",low);
   }
    return 0;
}