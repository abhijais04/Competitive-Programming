#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sc(x) scanf("%d",&x)
vector<string> names;
vector<string> input;
vector<string> ans;
int main()
{
    string s = "A";
    for(char ch= 'a';ch<='z';ch++)
    {
        names.pb(s+ch);
    }
    s = "B";
    for(char ch  = 'a';ch<='z';ch++)
    {
        names.pb(s+ch);
    }

    int n,k;
    cin>>n>>k;
    for(int i=0;i<n-k+1;i++)
    {
        string str;
        cin>>str;
        input.pb(str);
    }

    int lused = -1;
    for(int i=0;i<k-1;i++)
    {
        ans.pb(names[i]);
        lused++;
    }
    for(int i=0;ans.size()<n;i++)
    {
        int sz = ans.size();
        if(input[i]=="NO")
        {
            ans.pb(ans[sz-k+1]);
        }
        else
        {
            lused++;
            ans.pb(names[lused]);
        }
    }

    for(int i=0;i<n;i++)
        cout<<ans[i]<<" ";
    return 0;
}