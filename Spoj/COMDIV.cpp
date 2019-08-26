#include<bits/stdc++.h>
using namespace std;
//int a[1000010];
//int n=1000010;
//vector <int>v[1000010];
/*void sieve()
{
    for(int i=3;i*i<=n;i+=2)
    {
        if(a[i]==0)
        {
            v[i].push_back(i);
            for(int j=i;j<=n;j+=i)
            {
                a[j]=1;
                v[j].push_back(i);
            }
        }
    }
}*/
int gcd(int a,int b)
{
    while(b)
    {
        int tmp=a%b;
        a=b;
        b=tmp;
    }
    return a;
}
int main()
{
  //  sieve();
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,cd;
        scanf("%d%d",&n,&m);
        cd=gcd(n,m);
        int ans=0;
        //cout<<cd<<"\n";
        for(int i=1;i*i<=cd;i++)
        {
        	if(cd%i==0)
        	{
        	    //cout<<"i "<<i;
        	    ans++;
        	    if(i*i!=cd)
                    ans++;
        	}
        }
        printf("%d\n",ans);
    }
    return 0;
}
