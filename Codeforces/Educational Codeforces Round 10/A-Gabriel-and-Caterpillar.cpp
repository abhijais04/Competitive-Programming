#include <bits/stdc++.h>
    using namespace std;
    int main()
    {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        //while(1)
        {
            int h1,h2;
        int a,b;
        cin>>h1>>h2;
        cin>>a>>b;
        int d=a-b;
        int ans=0;
        if(b>=a&&(h2-h1>a*8))
            {
                ans=-1;
                cout<<ans;
            }
        else
        {
            int p=h1;
            int h=0;
            while(h<8&&p<h2)
            {
                p+=a;
                h++;
            }
            //int tmp=(h2-p)/(12*(a-b));
            while(p<h2)
            {
                p=p-(b*12);
                p+=a*(12);
                h+=24;
            }
            if(h<=8)
                {
                    ans=0;
                    cout<<ans;
                }
            else
            {
            h=h+4;
            h=h/24;
            cout<<h;
            }

        }
        }
        return 0;
    }