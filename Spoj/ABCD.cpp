#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    scanf("%d",&n);
    string s;
    cin>>s;
    int l=s.length(),i,j;
    char s2[l+5];
    for(i=0;i<l-1;i=i+2)
    {
        //cout<<s[i]<<" "<<(char)fn(s[i])<<"\n";
        //cout<<s[i+1]<<" "<<(char)fn(s[i+1])<<"\n";
        for(j='A';j<='D';j++)
        {
            if(j!=s[i]&&j!=s[i+1])
            {
                s2[i]=j;
                break;
            }
        }
        for(j='A';j<='D';j++)
        {
            if(j!=s[i]&&j!=s[i+1]&&j!=s2[i])
            {
                s2[i+1]=j;
            }
        }
        if(i>0)
        {
            int a=s2[i];
            int b=s2[i-1];
            if(a==b)
            {
                
                //cout<<"con true : "<<a<<" "<<b<<"\n";
            int tmp=s2[i];
            s2[i]=s2[i+1];
            s2[i+1]=tmp;
            }
            //cout<<s2[i]<<s2[i+1]<<"\n";
        }
    }
    s2[l]='\0';
    //cout<<s<<"\n";
    puts(s2);
	return 0;
}
