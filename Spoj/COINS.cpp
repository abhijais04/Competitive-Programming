#include<bits/stdc++.h>
using namespace std;
map <long long int ,long long int>m;
long long val(long long i)
{
	map<long long int,long long int>::iterator p;
    if(i<12)
        return i;
   	else
   	{
   		p=m.find(i);
   		if(p!=m.end())
   		return m[i];
   		m[i]=(max(i,(val(i/2)+val(i/3)+val(i/4))));
   		return m[i];
   	}
}
int main()
{
    long long n;
    while(scanf("%lld",&n)==1)
    {
        printf("%lld\n",val(n));
    }
    return 0;
}
