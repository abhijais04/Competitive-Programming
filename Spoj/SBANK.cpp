#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        set <string >s;
        map <string ,int>m;
        int n;
        scanf("%d\n",&n);
        for(int i=0;i<n;i++)
        {
          //  scanf("\n");
            string ch;
            getline(cin,ch);
            s.insert(ch);
            m[ch]+=1;
        }
        set <string>::iterator it;
        for(it=s.begin();it!=s.end();it++)
        {
            cout<<*it;
            printf(" %d",m[*it]);
            printf("\n");
        }
    }
    return 0;
}
