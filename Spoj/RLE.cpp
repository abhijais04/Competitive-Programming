#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    char str[1000000];

    while(scanf("%s",str)==1)
    {
        vector <char>v;
        int l=strlen(str);
        for(int i=0;i<l;)
        {
            int cnt=0;
            char c=str[i];
            while(str[i]==c)
            {
                i++;
                cnt++;
            }
            if(cnt>3)
            {
                cout<<cnt<<"!";
                cout<<c;
            }
            else
            {
                while(cnt--)
                    cout<<c;
            }
        }
        cout<<"\n";
    }
    return 0;
}
