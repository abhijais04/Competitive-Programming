#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
bool ont[100010];
int main()
{
    int n;
    cin>>n;
    int ans=0,cur=0;;
    for(int i=0;i<2*n;i++)
    {
        int k;
        cin>>k;
        if(ont[k]==1)
        {
            cur--;
            ont[k]=0;
            ans=max(ans,cur);
        }
        else
            {
                ont[k]=1;
                cur++;
                ans=max(ans,cur);
            }
    }
    cout<<ans<<"\n";
    return 0;

}