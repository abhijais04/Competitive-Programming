#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	//scanf("%d",&t);
	//while(t--)
	 {

	    int n;
	    long long m;
	    scanf("%d %lld",&n,&m);
	    long long a[n],i,j,mn=0,sum=0;
	    for(i=0;i<n;i++)
		 scanf("%lld",&a[i]);
        i=0;
        j=0;
        while(i<n&&j<n)
        {
            sum+=a[i];
            if(sum<=m)
            {
               if(sum>mn)
                mn=sum;
            }
            else
            {
                while(sum>m&&i>=j)
                {
                    sum-=a[j];
                    if(sum<=m&&sum>mn)
                        mn=sum;
                    if(i==j)
                        break;
                    j++;
                }
            }
            i++;
        }
        printf("%lld\n",mn);
	 }
return 0;
 }
