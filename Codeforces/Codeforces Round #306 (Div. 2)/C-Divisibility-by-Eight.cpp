#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int main()
{
    string str;
    cin>>str;
    int l=str.length();
    int ans=-1;
    int flag=0;
    for(int i=l-1;i>=0;i--)
    {
        int num = (int)(str[i]-'0');
        if(num%8==0)
        {
            ans=num;
            break;
        }
        for(int j=i-1;j>=0;j--)
        {
            int num1 = (int)(str[j]-'0')*10;
            num1+=num;
            if(num1%8==0)
            {
                ans=num1;
                flag=1;
                break;
            }
            for(int k=j-1;k>=0;k--)
            {
                int num2 = (int)(str[k]-'0')*100;
                num2+=num1;
                if(num2%8==0)
                {
                    ans=num2;
                    flag=1;
                    break;
                }
            }
            if(flag==1)
            {
                break;
            }
        }
        if(flag==1)
            break;
    }
    if(ans!= -1)
        cout<<"YES\n"<<ans<<"\n";
    else
        cout<<"NO\n";
    return 0;

}