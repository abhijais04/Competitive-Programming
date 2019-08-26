#include <bits/stdc++.h>
using namespace std;
int main()
{
    while(1)
    {
        string str;
        getline(cin,str);
        if(str[0]=='*')
            break;
        int a=str[0];
        int flag=1,i;
        for(i=1;i<str.length();i++)
        {
            if(str[i-1]==' ')
            {
                if((str[i]==a)||(a<=90&&str[i]==a+32)||(a>96&&str[i]==a-32))
                    flag=1;
                else
                {
                    flag=0;
                    break;
                }
            }
        }
        if(flag)
            cout<<"Y\n";
        else
            cout<<"N\n";
    }
    return 0;
}
