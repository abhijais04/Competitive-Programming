#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
//int val[40];
int main()
{
    int t;
    cin>>t;
   // scanf("\n");
   //string junk;
   string str,word;
   getline(cin,str);
    while(t--)
    {
        getline(cin,str);
        int pre=-1;
        int mx=0;
        int now=0;
        istringstream iss(str, istringstream::in);
        while(iss>>word)
        {
            if(word.length()==pre)
            {
                now++;
                mx=max(mx,now);
            }
            else
            {
                pre=word.length();
                now=1;
            }
            mx=max(now,mx);
        }
        cout<<mx<<"\n";
    }
    return 0;
}
