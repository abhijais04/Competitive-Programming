#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
   // char ch[n][m+1];
    int i,j;
    int flag=1;
    //for(i=0;i<n;i++)
     //   cin>>ch[i];
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            char ch[4];
            cin>>ch;
            if(ch[0]!='B'&&ch[0]!='W'&&ch[0]!='G')
            {
                flag=0;
             //   break;
            }
        }
        //if(flag==0)
          //  break;
    }
    if(flag==0)
        cout<<"#Color\n";
    else
        cout<<"#Black&White\n";
        return 0;
}