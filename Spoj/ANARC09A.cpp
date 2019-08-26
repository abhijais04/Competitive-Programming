#include <bits/stdc++.h>
using namespace std;

int main() {
	int t=1;
	//scanf("%d",&t);
	while(1)
	{
	   int c1=0,c2=0,i;
	   char ch[2300];
	   scanf("%s",&ch);
	   int l=strlen(ch);
	   int ans=0;
	   if(ch[0]=='-')
	   break;
	   for(i=0;i<l;i++)
	   {
	       if(ch[i]=='{')
	       {
	       	c1++;
	       }
	       else if(ch[i]=='}')
	       {
	           if(c1>0)
	           {
	           	c1--;
	           }
	           else
	           c2++;
	       }
	       else if(ch[i]=='-')
	       break;
	   }
	   if(i<l)
	   break;
	   ans=(c1+c2)/2;
	   if(c1%2==1||c2%2==1)
	   ans++;
	   printf("%d. %d\n",t,ans);
	   t++;
	}
	
	return 0;
}
