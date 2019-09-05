#include <iostream>
using namespace std;
bool a1[1010],b1[1010];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,i,j;
    cin>>n;
    int c;
    cin>>c;
    int p[n],t[n];
    for(i=0;i<n;i++)
        cin>>p[i];
    for(i=0;i<n;i++)
        cin>>t[i];
    int t1=0,t2=0;
    int tmp=0;
    for(i=0;i<n;i++)
    {
        tmp+=t[i];
        t1+=max(0,p[i]-(c*tmp));
    }
    tmp=0;
    for(i=n-1;i>=0;i--)
    {
        tmp+=t[i];
        t2+=max(0,p[i]-(c*tmp));
    }
    if(t1>t2)
        cout<<"Limak\n";
    else if(t2>t1)
        cout<<"Radewoosh\n";
    else
        cout<<"Tie\n";
    return 0;
}