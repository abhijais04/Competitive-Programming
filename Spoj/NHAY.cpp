#include <bits/stdc++.h>
using namespace std;
int main()
{
    scanf("\n");
    int lp;
    while(cin>>lp)
    {
        string text,pat;
        int i;
        cin>>pat >>text;
        string s=pat+"$"+text;
        int n=s.length();
        vector <int> z(n,0);
    int l,r;
    l=r=0;
    for(i=1;i<n;i++)
    {
        if(i>r)
        {
            l=r=i;
            while(r<n&&s[r-l]==s[r])
                r++;
            z[i]=r-l;
            r--;
        }
        else
        {
           int k1=i-l;
            int b=r-i+1;
            if(z[k1]<b)
                z[i]=z[k1];
            else
            {
                l=i;
                while(r<n&&s[r-l]==s[r])
                    r++;
                z[i]=r-l;
                r--;
            }
        }
    }
        int q=0;
        for(i=lp;i<n;i++)
            {
                if(z[i]>=lp)
                {
                    printf("%d\n",i-lp-1);
                    q=1;
                }
            }
        if(q==1)printf("\n");
    }
    return 0;
}
