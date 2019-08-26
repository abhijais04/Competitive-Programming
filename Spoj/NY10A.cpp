#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	map <string,int  >m;
	while(t--)
	{
		// TTT, TTH, THT, THH, HTT, HTH, HHT and HHH
		m["TTT"]=0;m["TTH"]=0;m["THT"]=0;m["THH"]=0;m["HTT"]=0;m["HTH"]=0;m["HHT"]=0;m["HHH"]=0;
		int a;
		char ch[41];
		char c[4];
		scanf("%d",&a);
		scanf("%s",&ch);
		for(int i=0;i<38;i++)
		{
			c[0]=ch[i];
			c[1]=ch[i+1];
			c[2]=ch[i+2];
			c[3]='\0';
			m[c]++;
		}
		cout<<a<<" "<<m["TTT"]<<" "<<m["TTH"]<<" "<<m["THT"]<<" "<<m["THH"]<<" "<<m["HTT"]<<" "<<m["HTH"]<<" "<<m["HHT"]<<" "<<m["HHH"]<<"\n";
	}
	return 0;
}