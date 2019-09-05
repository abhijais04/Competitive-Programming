#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sc(x) scanf("%d",&x)
int a[300010];
int n;
int k = 20;
int table[300001][21],gcd[300001][21];
void rmqgcd()
{
    // preprocess
    for(int i = 0; i < n; i++)
        gcd[i][0] = a[i];
    for(int j = 1; j <= k; j++) {
        for(int i = 0; i <= n - (1 << j); i++)
            gcd[i][j] = __gcd(gcd[i][j - 1], gcd[i + (1 << (j - 1))][j - 1]);
    }
}

void rmqmin()
{
    for(int i = 0; i < n; i++)
        table[i][0] = a[i];
    for(int j = 1; j <= k; j++) {
        for(int i = 0; i <= n - (1 << j); i++)
            table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
    }
}
int gcdquery(int L,int R)
{
    int answer = 0;
        for(int j = k; j >= 0; j--) {
            if(L + (1 << j) - 1 <= R) {
                answer = __gcd(answer, gcd[L][j]);
                L += 1 << j; // instead of having L', we increment L directly
            }
        }
    return answer;
}
int mnquery(int L,int R)
{
        int answer = INT_MAX;;
        for(int j = k; j >= 0; j--) {
            if(L + (1 << j) - 1 <= R) {
                answer = min(answer, table[L][j]);
                L += 1 << j;     // instead of having L', we increment L directly
            }
        }
        return answer;
}
bool check(int k)
{
    for(int i=0;i+k-1<n;i++)
    {
        int l = i;
        int r = i+k-1;
        int mnlr = mnquery(l,r);
        int gcdlr = gcdquery(l,r);
        if(mnlr == gcdlr)
            return true;
    }
    return false;
}
vector<int> ans;
int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    sc(n);
    for(int i=0;i<n;i++)
        sc(a[i]);
    rmqgcd();
    rmqmin();
    int l=1,h=n,mid;
    while(l<=h)
    {
        mid = (l+h)/2;
        if(check(mid))
            l=mid+1;
        else
            h=mid-1;
    }
    for(int i=0;i+h-1<n;i++)
    {
        int l=i,r=i+h-1;
        int m1 = mnquery(l,r);
        int m2 = gcdquery(l,r);
        if(m1==m2)
            ans.pb(i);
    }
    cout<<ans.size()<<" "<<h-1<<"\n";
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]+1<<" ";
    cout<<"\n";
      return 0;
}