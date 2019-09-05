#include<bits/stdc++.h>
using namespace std;
int main()
{
    int l;
    cin>>l;
    string str;
    cin>>str;

    int in=0,out=0;
    int flag=0;
    int cur=0;
    for(int i=0;i<l;i++)
    {
        if(str[i]=='(')
            {

                {
                    out=max(out,cur);
                }
                cur=0;
                flag++;
            }
        else if(str[i]==')')
            {
                if(cur>0)
                in++;
                cur=0;
                flag--;
            }
        else if(str[i]=='_')
        {
            if(flag>0)
            {
                if(cur>0)
                in++;
            }
            else
            {
                out=max(out,cur);
            }
            cur=0;
        }
        else
            cur++;
    }
    out=max(out,cur);
    cout<<out<<" "<<in<<"\n";
}