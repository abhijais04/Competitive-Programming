#include <bits/stdc++.h>
using namespace std;
int z[1000010];
void zalgo(string s)
{
    z[0]=0;
    int r=0,l=0;
    int len=s.length();
    int i;
    for(i=1;i<len;i++)
    {
        if(r<i)
        {
            r=l=i;
            while(r<len&&s[r]==s[r-l])
            {
                r++;
            }
            r--;
            z[i]=r-l+1;
        }
        else
        {
            int k=i-l;
            if(z[k]<r-i+1)
            z[i]=z[k];
            else
            {
                l=i;
                while(r<len&&s[r]==s[r-l])
                r++;
                r--;
                z[i]=r-l+1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	while(1)
	{
	    int x,i;
	    cin>>x;
	    string s;
	    cin>>s;
	    if(x==-1&&s[0]=='*')
	    break;
	    for(i=0;i<s.length();i++)
	    z[i]=0;
	    zalgo(s);
	    int l=s.length();
	    int mx=0;
	    for(i=0;i<l;i++)
	    {
	    	if(z[i]>mx&&z[i]+i==l)
	    	mx=z[i];
	    }
	    int ans;
	    //cout<<mx<<"\n";
	    if(mx>0)
	    ans=1+(x-l)/(l-mx);
	    else
	    ans=x/l;
	    if(ans<=0||x<l)
	    ans=0;
	    cout<<ans<<"\n";
	}
	return 0;
}
